//#define _AFXDLL
#include <afxwin.h>
#include "ICONDIR.h"
#include "ICONDIRENTRY.h"
#include "GRPICONDIR.h"
#include "GRPICONDIRENTRY.h"
#include "ChangeIcon.h"

ChangeIcon::ChangeIcon() 
{
}

ChangeIcon::~ChangeIcon() 
{
}

void ChangeIcon::ChangeExeIcon(LPCSTR iconFile, LPCSTR exeFile){
	ICONDIR stID;
	ICONDIRENTRY stIDE;
	
	GRPICONDIR stGID;
	HANDLE hFile;
	DWORD nSize, nGSize, dwReserved;
	HANDLE hUpdate;
	PBYTE pIcon, pGrpIcon;
	BOOL ret;


	hFile = CreateFile(iconFile, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE){
		return;
	}

	ZeroMemory(&stID, sizeof(ICONDIR));
	ret = ReadFile(hFile, &stID, sizeof(ICONDIR), &dwReserved, NULL);

	ZeroMemory(&stIDE, sizeof(ICONDIRENTRY));
	ret = ReadFile(hFile, &stIDE, sizeof(ICONDIRENTRY), &dwReserved, NULL);

	
	nSize = stIDE.dwBytesInRes;
	//pIcon = (PBYTE)malloc(nSize)
	pIcon = new BYTE(nSize);

	SetFilePointer(hFile, stIDE.dwImageOffset, NULL, FILE_BEGIN);
	ret = ReadFile(hFile, (LPVOID)pIcon, nSize, &dwReserved, NULL);
	if (!ret){
		CloseHandle(hFile);
		return;
	}

	ZeroMemory(&stGID, sizeof(GRPICONDIR));
	stGID.idCount = stID.idCount;
	stGID.idReserved = 0;
	stGID.idType = 1;

	CopyMemory(&stGID.idEntries, &stIDE, 12);
	stGID.idEntries.nID = 0;

	nGSize = sizeof(GRPICONDIR);
	//pGrpIcon = (PBYTE)malloc(nGSize);
	pGrpIcon = new BYTE(nGSize);
	CopyMemory(pGrpIcon, &stGID, nGSize);

	hUpdate = BeginUpdateResource(exeFile, false);

	
}
