///////////////////////////////////////////////////////////
//  CopyFile.h
//  Implementation of the Class CopyFile
//  Created on:      11-七月-2016 10:08:41
//  Original author: huang.hao
///////////////////////////////////////////////////////////

#if !defined(EA_7D0C7380_A343_41a4_8F12_94ECE230CCFA__INCLUDED_)
#define EA_7D0C7380_A343_41a4_8F12_94ECE230CCFA__INCLUDED_

/**
 * 复制文件
 */
class CopyFile
{

public:
	CopyFile();
	virtual ~CopyFile();

	int copyFile(char * sourceFile, char * newFile);

};
#endif // !defined(EA_7D0C7380_A343_41a4_8F12_94ECE230CCFA__INCLUDED_)
