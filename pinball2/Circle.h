#ifndef INCLUDED_CIRCLE_H
#define INCLUDED_CIRCLE_H
#include "image.h"
//ボール状の形の物体の情報を保持する。ワールド座標とはピクセル座標の1000倍になっているとする。
class Circle{
public:
	Circle(int radius//半径
		,int worldx//初期x座標
		,int worldy//初期y座標
		, int mass//重さ
		, int mvx//初期x速度
		,int mvy//初期y速度
		,char* filename);//絵のデータの名前
	virtual ~Circle(void);

	int mRadius;
	int mWorldx;
	int mWorldy;
	int mMass;
	int mVx;
	int mVy;
	bool isIntersected(const Circle& ball)const;//ほかのボールと衝突状態であるかどうかチェック
	virtual void attacked(Circle* ball);//衝突処理
	void draw(void);//自分を書く
	virtual void move(void);//自分のワールド座標に速度を足す。
	image* pic;
	bool ispenetrated[5];//自分が今現在どのボールと衝突状態にあるかどうかチェックする配列ispenetrated[i]=true
	//だと自分はiと衝突しているということ。

};

#endif;