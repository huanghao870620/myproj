#ifndef DRAWFLAG_H
#define DRAWFLAG_H
class DrawFlag;
static DrawFlag * instance;
class DrawFlag
{
private:
	DrawFlag(){
		this->flag = false;
	}
	

    public:
        ~DrawFlag(); 
		void setFlag(bool  flag);
		bool & getFlag();

		static DrawFlag * GetInstance(){
			if (instance == nullptr){
				instance = new DrawFlag;
			}
			return instance;
		}

	private:
		bool flag;
};
		



#endif
