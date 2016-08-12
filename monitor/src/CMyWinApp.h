#ifndef CMYWINAPP_H
#define CMYWINAPP_H
#include <afxwin.h>
class CMyWinApp : public CWinApp
{
    public:
        CMyWinApp(); 
        ~CMyWinApp(); 
        BOOL InitInstance();
		void init();
};  



#endif
