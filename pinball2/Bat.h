#ifndef INCLUDED_BAT_H
#define INCLUDED_BAT_H
#include "Circle.h"
//バットの情報を持っている　普通の玉と衝突処理だけが違う。
class Bat : public Circle{
public:
	Bat(int radius,int worldx, int worldy,char* filename);
	void attacked(Circle* ball);
	void move(void);


};

#endif;