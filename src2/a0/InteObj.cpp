
//#include <afxwin.h>
//#include <TlHelp32.h>
#include "InteObj.h"

InteObj::InteObj() 
{
}

InteObj::~InteObj() 
{
}
//
//BOOL InteObj::KillProcessFromName(CString strProcessName){
//	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//	PROCESSENTRY32 pe;
//	pe.dwSize = sizeof(PROCESSENTRY32);
//	if (!Process32First(hSnapShot, &pe)){
//		return FALSE;
//	}
//	strProcessName.MakeLower();
//	while (Process32Next(hSnapShot,&pe))
//	{
//		CString scTmp = pe.szExeFile;
//		scTmp.MakeLower();
//		if (!scTmp.Compare(strProcessName)){
//			DWORD dwProcessID = pe.th32ProcessID;
//			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, dwProcessID);
//			TerminateProcess(hProcess, 0);
//			CloseHandle(hProcess);
//			return TRUE;
//		}
//		scTmp.ReleaseBuffer();
//	}
//	strProcessName.ReleaseBuffer();
//	return FALSE;
//}