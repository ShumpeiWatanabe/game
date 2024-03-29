#include "game.h"
#include "State.h"
#include "GameLib/Framework.h"
#include "play.h"
#include "mainloop.h"
#include "top.h"
using namespace GameLib;

game::~game(){
	delete field;
	field = 0;
	delete now;
	now = 0;
	next = 0;
	
}

game::game(int max){//引数には勝負を決める点数を代入する
	Framework::instance().setFrameRate(60);
	field = new State();
	now = new play();
	next = now;
	mMaxpoint = max;
}

void game::update(base* parent){
	mainloop* mloop = dynamic_cast<mainloop*>(parent);
	if(0!= dynamic_cast<top*>(next)){
		mloop->next =new top();//遷移があった場合はnextに次の遷移が書き込まれている。
		return;
	}
	if(next != now){
		delete now;
		now = next;
	return;
	}
	else{
		now->update(this);
	}
}

void game::reset(){
	field ->reset();
}
