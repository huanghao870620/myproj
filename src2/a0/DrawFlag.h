#ifndef DRAWFLAG_H
#define DRAWFLAG_H

class DrawFlag
{
    public:
        DrawFlag(); 
        ~DrawFlag(); 
		void setFlag(bool  flag);
		bool & getFlag();

	private:
		bool flag;
};



#endif
