///////////////////////////////////////////////////////////
//  upload_service.h
//  Implementation of the Class upload_service
//  Created on:      28-Ê®Ò»ÔÂ-2016 17:42:12
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_F3EEAFCE_C113_45ab_A059_42D07323A249__INCLUDED_)
#define EA_F3EEAFCE_C113_45ab_A059_42D07323A249__INCLUDED_
#include"UploadFile.h"
#include"file_dao.h"
#include"db_util.h"
#include"Util.h"
#include"file.h"
class upload_service
{
public:
	upload_service();
	virtual ~upload_service();
private:file_dao*fd;
private:std::auto_ptr<odb::database> db;
public:static upload_service* get_upload_service(){
	static upload_service us;
	return &us;
}
public:void upload_file(file&f, LPCSTR localFilePath,long file_type);
public:void upload_file_no_tran(file&f, LPCSTR  localFilePath, long file_type);

};
#endif // !defined(EA_F3EEAFCE_C113_45ab_A059_42D07323A249__INCLUDED_)
