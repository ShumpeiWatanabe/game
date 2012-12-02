#include "config.h"
#include "font.h"
#include "GameLib/Framework.h"
#include "mainloop.h"
#include "top.h"
using namespace GameLib;
config::config(){
}

config::~config(){
}

void config::update(base *parent){
	mainloop* mloop = dynamic_cast<mainloop*>(parent);
	//情報を表示
	font::instance()->drawString(5,5,"endlessmode press e");
	font::instance()->drawString(5,6,"20point mode press t");
	//eが押されていたらエンドレスモード　選択したらtopに戻る
	if(Framework::instance().isKeyOn('e')){
		mloop->maxpoint = -1;
		mloop->next = new top();
		return;
	}
	//tが押されていたら20点モード　選択したらtopへ戻る
	if(Framework::instance().isKeyOn('t')){
		mloop->maxpoint = 20;
		mloop->next = new top();
	}
}