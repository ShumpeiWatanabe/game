#include "GameLib/Framework.h"
using namespace GameLib;
#include "menu.h"
#include "game.h"
#include "play.h"
#include "top.h"
#include "font.h"
void menu::update(base* parent){
	font::instance()->drawString(5,5,"reset r");//情報の表示
	font::instance()->drawString(5,6,"top t");
	font::instance()->drawString(5,7,"continue play c");
	game* gameplay = dynamic_cast<game*>(parent);
	//もし試合がおわっていたらおめでとうを表示
	if(gameplay->field->point1 == gameplay->mMaxpoint){
		font::instance()->drawString(5,4,"player1 congratulations!");
	}
	if(gameplay->field->point2 == gameplay->mMaxpoint){
		font::instance()->drawString(5,4,"player2 congratulations!");
	}
	//rで初期状態。押したらプレイに戻る
	if(Framework::instance().isKeyOn('r')){
		gameplay->reset();
		gameplay->next = new play();
		return;			
	}
	//ｔだったらtopに戻る。親のnextに次の遷移場所を書き込む。
	if(Framework::instance().isKeyOn('t')){
		gameplay->next = new top();
		return;
	}
	//cだったらプレイ再開。
	if(Framework::instance().isKeyOn('c')){	
		gameplay->next = new play();
		return;
	}

}

menu::menu(){
}

menu::~menu(){
}
