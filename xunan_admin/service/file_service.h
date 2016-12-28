///////////////////////////////////////////////////////////
//  file_service.h
//  Implementation of the Class file_service
//  Created on:      27-十一月-2016 17:30:07
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_FFC473C9_FFCF_4478_B7B8_3CE0DA4B2214__INCLUDED_)
#define EA_FFC473C9_FFCF_4478_B7B8_3CE0DA4B2214__INCLUDED_
//
#include<memory>
#include<odb\database.hxx>
#include<odb\transaction.hxx>
#include<odb\mysql\database.hxx>
#include"../util/db_util.h"
#include"../entity/file.h"
#include"../odb/file-odb.hxx"
#include"../dao/file_dao.h"
#include"../dao/good_file_dao.h"
#include"../entity/good_file.h"
#include"base_service.h"
#include"../util/Constants.h"

class UploadFile;
class Util;
class file_service : public base_service<file,file_dao>
{

public:
		file_service();
		virtual ~file_service();
		static file_service* get_file_service(){
			static file_service fs;
			return &fs;
		}
		void add_file(file&f);
		void update_file(file&f);
		void update_and_upload_file(long file_id, std::string&localPath, long fileTypeId);
		void add_good_file(std::string&localPath, long good_id, long file_type);/*添加商品文件*/
		std::string& downloadFtpFile(std::string&uriPath);
private:
		good_file_dao*gfd;
		std::string getPath(std::string&path, std::string&filename);
		std::string myReplaceAll(const std::string& str, std::string org_str, std::string rep_str);
		std::vector<std::string> mySplit(const std::string& str, std::string sp_string);
		BOOL CreateMuliteDirectory(CString P);
		BOOL FolderExists(CString s);
};
#endif // !defined(EA_FFC473C9_FFCF_4478_B7B8_3CE0DA4B2214__INCLUDED_)
