#include "GameLib/Framework.h"
#include "mainloop.h"
#include "top.h"
#include "game.h"
#include "font.h"
#include "config.h"
using namespace GameLib;

top::top(){
	pic = new image("picture/hockey.dds");
}

top::~top(){
	delete pic;
	pic = 0;
}

void top::update(base* kore){
	mainloop* mloop = dynamic_cast<mainloop*>(kore);
	pic->draw();//�\����ʂ�`��
	int h = Framework::instance().height();

	//�����A�X�y�[�X����������config ������ăQ�[���ݒ胂�[�h�Ɉڍs����
	font::instance()->drawString(0,h/16-1,"press space to set GAMEMODE");
	if(Framework::instance().isKeyOn(' ')){
		mloop->next = new config();
		return;
	}
	//�����Ai ���������΁A�Q�[���J�n
	bool i  = Framework::instance().isKeyOn('i');
	if(i == false){
	}
	else{
		mloop->next = new game(mloop->maxpoint);	
	}
	

}