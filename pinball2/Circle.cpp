#include "Circle.h"
#include "image.h"
#include "GameLib/Framework.h"
#include "math.h"
using namespace GameLib;
//衝突判定を行う。ボール同士の中心間距離が、ボール同士の半径の和より、短ければあたっている。
bool Circle::isIntersected(const Circle &ball)const{
	int dx = (ball.mWorldx - mWorldx)/10;
	int dy = (ball.mWorldy - mWorldy)/10;
	int sum = (ball.mRadius + mRadius)/10;
	if(dx*dx + dy*dy <= sum*sum){
			return true;//ぼーるとあたっているときにはtrueを書き込む
	}
	else{
		return false;//あたっていないときにはfalse
	}
}
//衝突処理
	void Circle::attacked(Circle *ball){
		//衝突される側と衝突する側の情報をdouble型に変換。
	const double two = 2.0;
	double radius = mRadius;
	double worldx = mWorldx;
	double worldy = mWorldy;
	double mass = mMass;
	double vx = mVx;
	double vy = mVy;

	double bradius = ball->mRadius;
	double bworldx = ball->mWorldx;
	double bworldy = ball->mWorldy;
	double bmass = ball->mMass;
	double bvx = ball->mVx;
	double bvy = ball->mVy;
//二つの円の中心間の距離を出す。
	double dis = sqrt((bworldx - worldx)*(bworldx-worldx)+(bworldy-worldy)*(bworldy-worldy));
	//衝突される側とする側の角度を出す。
	double cos = (bworldx -worldx)/dis;
	double sin = (bworldy- worldy)/dis;

	double xdash = cos*vx + sin*vy;//衝突される側の、衝突面に垂直な分の速度成分を出す。
	double ydash = sin*vx - cos*vy;//衝突される側の、衝突面に平行なな分の速度成分を出す。

	double bxdash = cos*bvx + sin*bvy;////衝突する側の、衝突面に垂直な分の速度成分を出す。
	double bydash = sin*bvx - cos*bvy;//衝突する側の、衝突面に垂直な分の速度成分を出す。
//運動量保存則と反発係数１により、衝突面に垂直な成分の速度の衝突後の速度を求める。
	double afterxdash = (mass-bmass)/(mass+bmass)*xdash + two*bmass/(mass+bmass)*bxdash;
	double afterbxdash = afterxdash - bxdash + xdash;
//求めた速度のｘ成分　y成分を求める。
	double avx = cos*afterxdash + sin*ydash;
	double avy = sin*afterxdash - cos*ydash;

	double abvx = cos*afterbxdash + sin*bydash;
	double abvy = sin*afterbxdash - cos*bydash;
//書き込む。
	this->mVx = static_cast<int>(avx);
	this->mVy = static_cast<int>(avy);

	ball->mVx = static_cast<int>(abvx);
	ball->mVy = static_cast<int>(abvy);
	//早すぎる場合は補正
	if(this->mVx > 16000){
		this->mVx = 16000;
	}
	if(this->mVy > 16000){
		this->mVy = 16000;
	}
	if(this->mVx < -16000){
		this->mVx = -16000;
	}
	if(this->mVy < -16000){
		this->mVy = -16000;
	}
	if(ball->mVx > 16000){
		ball->mVx = 16000;
	}
	if(ball->mVy > 16000){
		ball->mVy = 16000;
	}
	if(ball->mVx < -16000){
		ball->mVx = -16000;
	}
	if(ball->mVy < -16000){
		ball->mVy = -16000;
	}
}
//初期化
Circle::Circle(int radius,int worldx, int worldy, int mass, int mvx, int mvy,char* filename){
	this->mRadius = radius;
	this->mWorldx = worldx;
	this->mWorldy = worldy;
	this->mMass = mass;
	this->mVx = mvx;
	this->mVy = mvy;
	pic = new image(filename);
	for(int i = 0; i< 5; i++){
		ispenetrated[i] = false;
	}
}

//描画
void Circle::draw(){
	pic->draw(((mWorldx-mRadius)+500)/1000,((mWorldy-mRadius)+500)/1000,0,0,pic->mWidth,pic->mHeight);
}

Circle::~Circle(){
	delete pic;
	pic  = 0;
}

void Circle::move(void){
	mWorldx +=mVx;
	mWorldy +=mVy;
}



