#include "play.h"
#include "game.h"
#include "menu.h"
#include "GameLib/Framework.h"
#include "font.h"
using namespace GameLib;

play::play(){
}

play::~play(){
}

void play::update(base *parent){
	game* gameplay = dynamic_cast<game*>(parent);
	//フィールドを次のフレームの状態にする。
	gameplay->field->renew();
	//描画する。
	gameplay->field->draw();
	//ポイントを表示する。
	gameplay->field->printpoints();
   //スペースが押されてたらmenuに遷移
	if(Framework::instance().isKeyOn(' ')){
		gameplay->next = new menu(); return;
	}
	//画面下に情報を表示
	int i = Framework::instance().height();
	font::instance()->drawString(5,i/16-1,"press space to open menu");
	//勝負がついたらmenuに遷移
	if(gameplay->field->point1 == gameplay->mMaxpoint || gameplay ->field->point2 == gameplay->mMaxpoint){
		gameplay->next = new menu();
		return;
	}
}
