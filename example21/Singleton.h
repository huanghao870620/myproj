///////////////////////////////////////////////////////////
//  Singleton.h
//  Implementation of the Class Singleton
//  Created on:      12-Ê®ÔÂ-2016 17:35:34
//  Original author: huanghao
///////////////////////////////////////////////////////////

#if !defined(EA_69AD661B_6C40_49c8_9994_CA46974C9DBC__INCLUDED_)
#define EA_69AD661B_6C40_49c8_9994_CA46974C9DBC__INCLUDED_

#include<Windows.h>
#include"resource.h"
#include<windowsx.h>
#include<sddl.h>
#include<tchar.h>
#include<strsafe.h>

HWND g_hDlg;
HANDLE g_hSingleton = NULL;
HANDLE g_hBoundary = NULL;
HANDLE g_hNamespace = NULL;

BOOL g_bNamespaceOpened = FALSE;

PCTSTR g_szBoundary = "3-Boundary";
PCTSTR g_szNamespace = "3-Namespace";

#define DETAILS_CTRL GetDlgItem(g_hDlg, IDC_EDIT_DETAILS)

void AddText(PCTSTR pszFormat, ...){
	va_list argList;
	va_start(argList, pszFormat);
	TCHAR sz[20 * 1024];
	Edit_GetText(DETAILS_CTRL, sz, _countof(sz));
	_vstprintf_s(_tcschr(sz, '\0'), _countof(sz) - _tcslen(sz), pszFormat, argList);
	Edit_SetText(DETAILS_CTRL, sz);
	va_end(argList);
}

void Dlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify){
	switch (id)
	{
	case IDOK:
	case IDCANCEL:
		EndDialog(hwnd, id);
		break;
	default:
		break;
	}
}

void CheckInstances(){
	g_hBoundary = CreateBoundaryDescriptor(g_szBoundary, 0);
	BYTE localAdminSID[SECURITY_MAX_SID_SIZE];
	PSID pLocalAdminSID = &localAdminSID;
	DWORD cbSID = sizeof(localAdminSID);
	if (!CreateWellKnownSid(WinBuiltinAdministratorsSid,NULL,pLocalAdminSID,&cbSID)){
		AddText("AddSIDToBoundaryDescriptor failed: %u\r\n", GetLastError());
		return;
	}

	if (!AddSIDToBoundaryDescriptor(&g_hBoundary, pLocalAdminSID)){
		AddText("AddSIDToBoundaryDescriptor failed: %u\r\n", GetLastError());
		return;
	}

	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.bInheritHandle = FALSE;
	if (!ConvertStringSecurityDescriptorToSecurityDescriptor("D:(A;;GA;;;BA)", SDDL_REVISION_1, &sa.lpSecurityDescriptor, NULL)){
		AddText("Security Descriptor creation failed: %u\r\n", GetLastError());
		return;
	}

	g_hNamespace = CreatePrivateNamespace(&sa, g_hBoundary, g_szNamespace);
	LocalFree(sa.lpSecurityDescriptor);

	DWORD dwLastError = GetLastError();
	if (g_hNamespace == NULL){
		if (dwLastError == ERROR_ACCESS_DENIED){
			AddText("Access denied when creating the namespace.\r\n");
			AddText("You must be running as Administrator.\r\n\r\n");
			return;
		}
		else{
			if (dwLastError == ERROR_ALREADY_EXISTS){
				AddText("", dwLastError);
			}
		}
	}
}

class Singleton
{

public:
	Singleton();
	virtual ~Singleton();

};
#endif // !defined(EA_69AD661B_6C40_49c8_9994_CA46974C9DBC__INCLUDED_)
