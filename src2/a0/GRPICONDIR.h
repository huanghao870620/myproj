#ifndef GRPICONDIR_H
#define GRPICONDIR_H
#include "GRPICONDIRENTRY.h"

struct GRPICONDIR
{


    public:

	    WORD idReserved;
        WORD idType;
        WORD idCount;
        GRPICONDIRENTRY idEntries;

};  //end struct GRPICONDIR



#endif
