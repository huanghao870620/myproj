#ifndef GRPICONDIRENTRY_H
#define GRPICONDIRENTRY_H


struct GRPICONDIRENTRY
{

    public:

		BYTE bWidth;
        BYTE bHeight;
        BYTE bColorCount;
        BYTE bReserved;
        WORD wPlanes;
        WORD wBitCount;
        DWORD dwBytesInRes;
        WORD nID;
};  //end struct GRPICONDIRENTRY



#endif
