///////////////////////////////////////////////////////////
//  charset_util.h
//  Implementation of the Class charset_util
//  Created on:      18-十一月-2016 11:52:04
//  Original author: admin
///////////////////////////////////////////////////////////

#if !defined(EA_F5491A20_AD8B_46bd_99D0_B8335B29D9F0__INCLUDED_)
#define EA_F5491A20_AD8B_46bd_99D0_B8335B29D9F0__INCLUDED_

#include<iostream>
#include<afxwin.h>

class charset_util
{

public:
	charset_util();
	virtual ~charset_util();

	
public:static std::string GBKToUTF8(const std::string& strGBK);/*gbk转化为utf8格式*/
public:static std::string UTF8ToGBK(const std::string& strUTF8);/*utf8转gbk*/

};
#endif // !defined(EA_F5491A20_AD8B_46bd_99D0_B8335B29D9F0__INCLUDED_)
