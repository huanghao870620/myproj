#ifndef ICONDIRENTRY_H
#define ICONDIRENTRY_H
//Begin section for file ICONDIRENTRY.h
//TODO: Add definitions that you want preserved
//End section for file ICONDIRENTRY.h




struct ICONDIRENTRY
{

    public:


        BYTE bWidth;
        BYTE bHeight;
        BYTE bColorCount;
        BYTE bReserved;
        WORD wPlanes;
        WORD wBitCount;
        DWORD dwBytesInRes;
        DWORD dwImageOffset;

};  //end struct ICONDIRENTRY



#endif
