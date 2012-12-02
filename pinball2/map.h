#ifndef INCLUDED_MAP_H
#define INCLUDED_MAP_H
#include "image.h"
/*壁とゴールの絵だけを持っているクラス。*/
class map{
public:
	map();
	~map(void);

	void draw(void);//壁とゴールを描画する。

	image* pic[2];//壁とゴールの絵を保持
	
};
#endif;