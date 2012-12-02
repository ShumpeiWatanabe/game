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
	//����\��
	font::instance()->drawString(5,5,"endlessmode press e");
	font::instance()->drawString(5,6,"20point mode press t");
	//e��������Ă�����G���h���X���[�h�@�I��������top�ɖ߂�
	if(Framework::instance().isKeyOn('e')){
		mloop->maxpoint = -1;
		mloop->next = new top();
		return;
	}
	//t��������Ă�����20�_���[�h�@�I��������top�֖߂�
	if(Framework::instance().isKeyOn('t')){
		mloop->maxpoint = 20;
		mloop->next = new top();
	}
}