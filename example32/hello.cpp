#include <boost/uuid/sha1.hpp>  
#include <iostream>  
/*  @brief
SHA1摘要<a href="http://lib.csdn.net/base/datastructure" class='replace_word' title="算法与数据结构知识库" target='_blank' style='color:#df3434; font-weight:bold;'>算法</a>:一种很重要的密码学算法,可将任意长度的文本压缩成20个字节的
独一无二的的摘要(uuid名字生成器使用该算法)
*/
using namespace boost::uuids::detail;
using namespace std;
int main()
{
	sha1    sha;        // 声明摘要对象  
	char*   szMsg = "This is a short message!";

	//--------------------------  
	// 向摘要压入文本  
	//--------------------------  

	// 第一种:  
	// 压入一个字节  
	sha.process_byte(0x10);
	// 第二种:  
	// 压入多个字节(指定字节数)  
	sha.process_bytes(szMsg, strlen(szMsg));
	// 第三种:  
	// 压入多个字节(指定指针范围,多少地址)  
	sha.process_block(szMsg, szMsg + strlen(szMsg));
	//---------------------------  
	// 取出摘要中加密后的内容  
	//---------------------------  
	// 声明摘要的返回值  
	unsigned int digest[5];                 // unsigned int(4个字节) * 5个unsigned int = 20 个字节  
	sha.get_digest(digest);                 // 返回压缩后的20个字节的摘要内容  
	for (int i = 0; i<5; ++i)
	{
		cout << hex << digest[i];            // 以十六进制输出  
	}
	cout << endl;
	for (int i = 0; i<5; ++i)
	{
		cout << digest[i];                 // 跟以十六进制输出的效果一样  
	}

	getchar();
	return 0;
}