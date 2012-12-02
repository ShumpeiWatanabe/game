#ifndef INCLUDED_STATE_H
#define INCLUDED_STATE_H
#include "base.h"
#include "Circle.h"
#include "image.h"
#include "map.h"
#include "GameLib/Framework.h"

/*ゲームのデータはすべてここで管理する。
ゲームを更新
ゲームを描画
得点計算*/
class State{
public:
	State();
	~State();

	void renew(void);//ゲーム状態の更新　入力をキャッチしてゲームを次のフレームの状態にする。
	void draw(void);//ゲームを描画する。
	void printpoints(void);//プレーヤーの得点を描画する。
	void reset(void);//ボールの位置と得点を初期化する。
	int point1;//プレイヤー１の得点を持つ
	int point2;//プレイヤー2の得点を持つ

private:
	Circle* packs[5];//2つのバットと3つのボールを持つ
	map* mMap;//壁とゴールの絵を持つ
	image* background;//背景の絵を持つ


};
#endif;