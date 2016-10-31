#include <boost/uuid/sha1.hpp>  
#include <iostream>  
/*  @brief
SHA1ժҪ<a href="http://lib.csdn.net/base/datastructure" class='replace_word' title="�㷨�����ݽṹ֪ʶ��" target='_blank' style='color:#df3434; font-weight:bold;'>�㷨</a>:һ�ֺ���Ҫ������ѧ�㷨,�ɽ����ⳤ�ȵ��ı�ѹ����20���ֽڵ�
��һ�޶��ĵ�ժҪ(uuid����������ʹ�ø��㷨)
*/
using namespace boost::uuids::detail;
using namespace std;
int main()
{
	sha1    sha;        // ����ժҪ����  
	char*   szMsg = "This is a short message!";

	//--------------------------  
	// ��ժҪѹ���ı�  
	//--------------------------  

	// ��һ��:  
	// ѹ��һ���ֽ�  
	sha.process_byte(0x10);
	// �ڶ���:  
	// ѹ�����ֽ�(ָ���ֽ���)  
	sha.process_bytes(szMsg, strlen(szMsg));
	// ������:  
	// ѹ�����ֽ�(ָ��ָ�뷶Χ,���ٵ�ַ)  
	sha.process_block(szMsg, szMsg + strlen(szMsg));
	//---------------------------  
	// ȡ��ժҪ�м��ܺ������  
	//---------------------------  
	// ����ժҪ�ķ���ֵ  
	unsigned int digest[5];                 // unsigned int(4���ֽ�) * 5��unsigned int = 20 ���ֽ�  
	sha.get_digest(digest);                 // ����ѹ�����20���ֽڵ�ժҪ����  
	for (int i = 0; i<5; ++i)
	{
		cout << hex << digest[i];            // ��ʮ���������  
	}
	cout << endl;
	for (int i = 0; i<5; ++i)
	{
		cout << digest[i];                 // ����ʮ�����������Ч��һ��  
	}

	getchar();
	return 0;
}