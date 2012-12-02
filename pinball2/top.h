#ifndef INCLUDED_TOP_H
#define INCLUDED_TOP_H
#include "base.h"
#include "image.h"
//top画面を表示するためのクラス
//config とgame 状態への分岐を行う
class top : public base{
public:
	top(void);
	~top(void);
	void update(base*);

	image* pic;
};
#endif;