#include "State.h"
#include "Circle.h"
#include "GameLib/Framework.h"
#include "Bat.h"
#include "font.h"
#include "map.h"
using namespace GameLib;


State::State():point1(0),point2(0){
	const int yoko = /*yoko*/Framework::instance().width();
	const int takasa = /*takasa*/Framework::instance().height();
	mMap = new map();

	packs[0] = new Bat(16*1000,32*1000+500,Framework::instance().height()*1000/2,"picture/bat.dds");
	packs[1] = new Bat(16*1000,(Framework::instance().width()-32)*1000-500,Framework::instance().height()*1000/2,"picture/bat.dds");
	packs[2] = new Circle(8*1000,yoko*1000/3*2,takasa*1000/2,20,300,0,"picture/pad.dds");
	packs[3] = new Circle(9*1000,yoko*1000/3,takasa*1000/2,70,-300,0,"picture/pad_g.dds");
	packs[4] = new Circle(12*1000,yoko*1000/2,takasa*1000/2,120,0,1000,"picture/pad_gr.dds");

	background = new image("picture/haikei.dds");

}

void State::renew(void){
	int i,j;
	for(i = 0; i < 5; i++){
		packs[i]->move();//すべてのパックを移動させる。
	}
	for(i = 0; i < 5; i++){//衝突していたら速度を更新する
		for(j = i+1; j< 5;j++){
			if(packs[i]->isIntersected(*packs[j]) == true){
				if(packs[i]->ispenetrated[j] == false || packs[j] ->ispenetrated[i] == false){
					packs[i]->attacked(packs[j]);
					
					packs[i] ->ispenetrated[j] = true;
					packs[j] ->ispenetrated[i] = true;
				}
			}
			else{
				packs[i]->ispenetrated[j] = false;
				packs[j]->ispenetrated[i] = false;
			}
		}
	}

	for(i = 0; i < 5; i++){//ゴールに当たっていたら跳ね返る
		if(packs[i]->mWorldx < (16000+packs[i]->mRadius)){
			if(packs[i]->mVx < 0){
				packs[i]->mVx *= -1;
				point2++;
			}
		}
		if(packs[i]->mWorldx > (Framework::instance().width() - 16 - packs[i]->mRadius/1000)*1000){
			if(packs[i]->mVx > 0){
				packs[i]->mVx *= -1;
				point1++;
			}
		}
		//ここからｙ軸
		if(packs[i]->mWorldy < (16000+packs[i]->mRadius)){
			if(packs[i]->mVy < 0){
				packs[i]->mVy *= -1;
			}
		}
		if(packs[i]->mWorldy > (Framework::instance().height()- 16 - packs[i]->mRadius/1000)*1000){
			if(packs[i]->mVy > 0){
				packs[i]->mVy *= -1;
			}
		}
	}
}

void State::draw(void){
	int i;
	int w = Framework::instance().width();
	int h = Framework::instance().height();

	
	background->draw();
	for(i = 0; i < 5; i++){	
		packs[i]->draw();
	}
	mMap->draw();
	font::instance()->drawString(0,0,"W");
	font::instance()->drawString(w/8-1,0,"I");
	font::instance()->drawString(0,h/16-1,"Z");
	font::instance()->drawString(w/8-1,h/16-1,"M");
}


void State::printpoints(void){
	font::instance()->drawString(5,0,"points");
	int tmp = point1%100/10;
	if(tmp == 0){
		font::instance()->drawString(13,0,"0");
	}
	if(tmp == 1){
		font::instance()->drawString(13,0,"1");
	}
	if(tmp == 2){
		font::instance()->drawString(13,0,"2");
	}
	if(tmp == 3){
		font::instance()->drawString(13,0,"3");
	}
	if(tmp == 4){
		font::instance()->drawString(13,0,"4");
	}
	if(tmp == 5){
		font::instance()->drawString(13,0,"5");
	}
	if(tmp == 6){
		font::instance()->drawString(13,0,"6");
	}
	if(tmp == 7){
		font::instance()->drawString(13,0,"7");
	}
	if(tmp == 8){
		font::instance()->drawString(13,0,"8");
	}
	if(tmp == 9){
		font::instance()->drawString(13,0,"9");
	}
	tmp = point1%10;
	if(tmp == 0){
		font::instance()->drawString(14,0,"0");
	}
	if(tmp == 1){
		font::instance()->drawString(14,0,"1");
	}
	if(tmp == 2){
		font::instance()->drawString(14,0,"2");
	}
	if(tmp == 3){
		font::instance()->drawString(14,0,"3");
	}
	if(tmp == 4){
		font::instance()->drawString(14,0,"4");
	}
	if(tmp == 5){
		font::instance()->drawString(14,0,"5");
	}
	if(tmp == 6){
		font::instance()->drawString(14,0,"6");
	}
	if(tmp == 7){
		font::instance()->drawString(14,0,"7");
	}
	if(tmp == 8){
		font::instance()->drawString(14,0,"8");
	}
	if(tmp == 9){
		font::instance()->drawString(14,0,"9");
	}
//////////////////////////////////////////////////////////
	 tmp = point2%100/10;
	if(tmp == 0){
		font::instance()->drawString(16,0,"0");
	}
	if(tmp == 1){
		font::instance()->drawString(16,0,"1");
	}
	if(tmp == 2){
		font::instance()->drawString(16,0,"2");
	}
	if(tmp == 3){
		font::instance()->drawString(16,0,"3");
	}
	if(tmp == 4){
		font::instance()->drawString(16,0,"4");
	}
	if(tmp == 5){
		font::instance()->drawString(16,0,"5");
	}
	if(tmp == 6){
		font::instance()->drawString(16,0,"6");
	}
	if(tmp == 7){
		font::instance()->drawString(16,0,"7");
	}
	if(tmp == 8){
		font::instance()->drawString(16,0,"8");
	}
	if(tmp == 9){
		font::instance()->drawString(16,0,"9");
	}
	 tmp = point2%10;
	if(tmp == 0){
		font::instance()->drawString(17,0,"0");
	}
	if(tmp == 1){
		font::instance()->drawString(17,0,"1");
	}
	if(tmp == 2){
		font::instance()->drawString(17,0,"2");
	}
	if(tmp == 3){
		font::instance()->drawString(17,0,"3");
	}
	if(tmp == 4){
		font::instance()->drawString(17,0,"4");
	}
	if(tmp == 5){
		font::instance()->drawString(17,0,"5");
	}
	if(tmp == 6){
		font::instance()->drawString(17,0,"6");
	}
	if(tmp == 7){
		font::instance()->drawString(17,0,"7");
	}
	if(tmp == 8){
		font::instance()->drawString(17,0,"8");
	}
	if(tmp == 9){
		font::instance()->drawString(17,0,"9");
	}
}

State::~State(){
	delete[] packs;
	for(int i = 0; i < 5; i++){
		packs[i] = 0;
	}
	delete background;
	background = 0;
}

void State::reset(){
	int w = Framework::instance().width();
	int h = Framework::instance().height();

	point1 = 0;
	point2 = 0;
	packs[2]->mVx = 300;
	packs[2]->mVy = 0;
	packs[2]->mWorldx = w*1000/3*2;
	packs[2]->mWorldy = h*1000/2;

	packs[3]->mVx = -300;
	packs[3]->mVy = 0;
	packs[3]->mWorldx = w*1000/3;
	packs[3]->mWorldy = h*1000/2;

	packs[4]->mVx=0;
	packs[4]->mVy = -1000;
	packs[4]->mWorldx = w*1000/2;
	packs[4]->mWorldy = h*1000/2;
}

	