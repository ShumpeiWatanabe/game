#ifndef INCLUDED_PLAY_H
#define INCLUDED_PLAY_H
#include "base.h"
//実際に遊ぶときに呼ばれているクラス
//メニュー画面への分岐を行う
class play : public base{
public:
	play();
	~play();
	void update(base* parent);//ゲームを次のフレーム状態にする、描画するなどの関数を呼び出す。

};

#endif;