#include "Bat.h"
#include "Circle.h"
#include "GameLib/Framework.h"
using namespace GameLib;

Bat::Bat(int radius, int worldx, int worldy, char *filename):Circle(radius,worldx,worldy,1000,0,0,filename){
;
}

//衝突処理　衝突処理を行った後、速度を0にする。
void Bat::attacked(Circle *ball){
	Circle::attacked(ball);
	mVx = 0;
	mVy = 0;
}

void Bat::move(void){
	mVx = 0;
	mVy = 0;
	mMass = 60000;//ボールが動いていないときにはすごく重たい設定にする。
	//左側の人player1のバットを動かす。
	if(this->mWorldx < Framework::instance().width()*1000/2){
		if(Framework::instance().isKeyOn('w')){
			mWorldy -= 1000;
			mVy = -1000;
			mMass = 200;//ボールが動いているときには軽めの設定にする。
		}
		if(Framework::instance().isKeyOn('z')){
			mWorldy += 1000;
			mVy = 1000;
			mMass = 200;
		}
	}
	else{//右側の人のバットを動かす。
		if(Framework::instance().isKeyOn('i')){
			mWorldy -= 1000;
			mVy = -1000;
			mMass = 200;
		}
		if(Framework::instance().isKeyOn('m')){
			mWorldy += 1000;
			mVy = 1000;
			mMass = 200;
		}
	}
	if(mWorldy >Framework::instance().instance().height()*1000-16500){
		mWorldy = Framework::instance().height()*1000-16500;
		mVy = 0;
	}
	if(mWorldy <16500){
		mWorldy = 16500;
		mVy =0;
	}

}