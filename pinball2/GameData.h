#ifndef INCLUDED_GAMEDATA_H
#define INCLUDED_GAMEDATA_H
#include "Circle.h"
#include "image.h"

class GameData{
public:
	GameData(void);
	~GameData(void);
	Circle ma;
	Circle mb;
	image* pic;
	
};
#endif;