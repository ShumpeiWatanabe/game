#ifndef INCLUDED_MENU_H
#define INCLUDED_MENU_H
#include "base.h"
//メニュー画面を保持しておく。ゲーム再開　top画面に戻る　初期状態に戻す の分岐を行う
class menu : public base{
public:
	menu();
	~menu();
	void update(base* parent);
};

#endif;
