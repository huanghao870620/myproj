/////////////////////////////////////////////////////////////
////  file_service.cpp
////  Implementation of the Class file_service
////  Created on:      27-十一月-2016 17:30:07
////  Original author: admin
/////////////////////////////////////////////////////////////
//
#include"../util/UploadFile.h"
#include"../util/Util.h"
#include "file_service.h"
//
//
file_service::file_service(){
	this->db = db_util::get_db_util()->get_db();
	this->d = file_dao::get_file_dao();
	this->gfd = good_file_dao::get_good_file_dao();
}



file_service::~file_service(){

}


void file_service::add_file(file&f){
	try{
		odb::core::transaction tx(this->db->begin());
		this->d->add(f, this->db);
		tx.commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
	}
}

void file_service::update_file(file&f){
	odb::core::transaction tx(this->db->begin());
	this->d->update(f,this->db);
	tx.commit();
}

/*修改和上传文件*/
void file_service::update_and_upload_file(long file_id,
	std::string&localPath, 
	long fileTypeId){
	std::string base;
	std::string id_str;
	std::string fileTypeIdStr;
	UploadFile uf;
	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	tran *tx = NULL;
	try{
		if (!t::has_current()){
		 tx = new  tran(this->db->begin());
		}
		else
		{
			tx = &(t::current());
		}
	file&f= this->d->findById(file_id, this->db);
	id_str = Util::ltos(f.get_id());
	fileTypeIdStr = Util::ltos(fileTypeId);
	uf.upload(localPath.c_str(), base, fileTypeIdStr.c_str(), id_str.c_str());
	f.set_uri_path(base);
	this->d->update(f, this->db);
	t::current().commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
		t::current().rollback();
	}
}


void file_service::add_good_file(std::string&localPath,long good_id,long file_type){

	typedef odb::core::transaction tran;
	typedef odb::transaction t;
	std::string path = "";
	std::string uri_path = "";
	file f;
	good_file gf;
	UploadFile uf;
	std::string base;
	tran *tx = NULL;
	try{
		if (!t::has_current()){
			tx = new tran(this->db->begin());
		}
		else
		{
			tx = &(t::current());
		}
	f.set_name("");
	f.set_path(path);
	f.set_type_id(file_type);
	f.set_uri_path(uri_path);
	long file_id=0;
	file_id= this->d->add(f, this->db);
	f.set_id(file_id);
	std::string id_str = Util::ltos(f.get_id());
	std::string fileTypeIdStr = Util::ltos(file_type);
	uf.upload(localPath.c_str(), base, fileTypeIdStr.c_str(), id_str.c_str());
	f.set_uri_path(base);
	this->d->update(f, this->db);
	
	gf.set_file_id(f.get_id());
	gf.set_good_id(good_id);
	this->gfd->add_good_file(gf, this->db);
	tx->commit();
	}
	catch (odb::exception&e){
		std::cout << e.what() << std::endl;
		tx->rollback();
	}
}



std::string& file_service::downloadFtpFile(std::string&uriPath){
	std::string url_str = "";
	Config *config= Config::getConfig();
	url_str = config->get_remote_path() + uriPath;/*服务器上ftp的路径*/

	std::string& localPath = config->get_local_path() + uriPath;/*ftp下载到本地的路径*/

	std::string resultPath; /*截取结果*/
	std::string filename; /*文件名*/
	resultPath = this->getPath(localPath, filename);/*获取路径*/
	resultPath = this->myReplaceAll(resultPath, "/", "\\");/*替换文件路径*/
	if (!PathIsDirectory(resultPath.c_str())){
		/*不存在则创建*/
		this->CreateMuliteDirectory(resultPath.c_str());
	}

	UploadFile *uf = new UploadFile;
	uf->download(url_str.c_str(), localPath.c_str()); /*下载文件到本地*/
	delete uf;
	return uriPath;
}



/*截取文件名*/
std::string file_service::getPath(std::string&path, std::string&filename){
	int lastp = path.find_last_of("/");
	std::string b = path.substr(0, lastp);
	filename = path.substr(lastp + 1);
	return b;
}


/**/
std::string file_service::myReplaceAll(const std::string& str, std::string org_str, std::string rep_str) // 把org_str 替换为rep_str; 
{
	std::vector<std::string>  delimVec = mySplit(str, org_str);
	if (delimVec.size() <= 0)
	{
		std::cout << "can not find" << std::endl;
		return str;
	}
	std::string target("");
	std::vector<std::string>::iterator it = delimVec.begin();
	for (; it != delimVec.end(); ++it)
	{
		target = target + (*it) + rep_str;
	}
	//target = target +(*it); 
	return target;
}




std::vector<std::string> file_service::mySplit(const std::string& str, std::string sp_string)  // split(), str 是要分割的string
{
	std::vector<std::string> vecString;
	int sp_stringLen = sp_string.size();
	int lastPosition = 0;
	int index = -1;
	while (-1 != (index = str.find(sp_string, lastPosition)))
	{
		vecString.push_back(str.substr(lastPosition, index - lastPosition));
		lastPosition = index + sp_stringLen;
	}
	std::string lastStr = str.substr(lastPosition);
	if (!lastStr.empty())
	{
		vecString.push_back(lastStr);
	}
	return vecString;
}



BOOL file_service::CreateMuliteDirectory(CString P)
{
	int len = P.GetLength();
	if (len <2) return false;
	if ('\\' == P[len - 1])
	{
		P = P.Left(len - 1);
		len = P.GetLength();
	}
	if (len <= 0) return false;
	if (len <= 3)
	{
		if (FolderExists(P))return true;
		else return false;
	}
	if (FolderExists(P))return true;
	CString Parent;
	Parent = P.Left(P.ReverseFind('\\'));
	if (Parent.GetLength() <= 0)return false;
	BOOL Ret = CreateMuliteDirectory(Parent);
	if (Ret)
	{
		SECURITY_ATTRIBUTES sa;
		sa.nLength = sizeof(SECURITY_ATTRIBUTES);
		sa.lpSecurityDescriptor = NULL;
		sa.bInheritHandle = 0;
		Ret = (CreateDirectory(P, &sa) == TRUE);
		return Ret;
	}
	else
		return FALSE;
}


BOOL file_service::FolderExists(CString s)
{
	DWORD attr;
	attr = GetFileAttributes(s);
	return (attr != (DWORD)(-1)) && (attr & FILE_ATTRIBUTE_DIRECTORY);
}

