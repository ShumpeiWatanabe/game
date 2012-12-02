#ifndef INCLUDED_GAME_H
#define INCLUDED_GAME_H
#include "base.h"
#include "State.h"
//ゲーム情報をすべて保持しておく
//play ,menu,状態の保持、分岐を行う
class game : public base{

public:
	game(int max);
	~game(void);
	void update(base*);//ゲームを毎フレーム更新する
	void reset(void);//ゲームを初期化する。
	State* field; //ゲーム情報を持つ
	base* now;
	base* next;
	int mMaxpoint;
};

#endif;