#ifndef LODIFFEGLOBAL_H
#define LODIFFEGLOBAL_H

class Global;
class LoDiffeGlobal
{

    public:
        LoDiffeGlobal(); 

        ~LoDiffeGlobal(); 


		void count(); // ����

		void weighing(); //����

		void messUp(); // ����

    private:
		Global * bals[9];
		

};  



#endif
