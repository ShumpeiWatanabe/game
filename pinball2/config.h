#ifndef INCLUDED_CONFIG_H
#define INCLUDED_CONFIG_H
#include "base.h"
//ゲームの設定をするクラス。終わると自動的にtop画面へと遷移する
class config : public base{
public:
	config();
	~config();
	void update(base* parent);
};
#endif;