#ifndef INCLUDED_BAT_H
#define INCLUDED_BAT_H
#include "Circle.h"
//�o�b�g�̏��������Ă���@���ʂ̋ʂƏՓˏ����������Ⴄ�B
class Bat : public Circle{
public:
	Bat(int radius,int worldx, int worldy,char* filename);
	void attacked(Circle* ball);
	void move(void);


};

#endif;