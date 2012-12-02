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
	//�t�B�[���h�����̃t���[���̏�Ԃɂ���B
	gameplay->field->renew();
	//�`�悷��B
	gameplay->field->draw();
	//�|�C���g��\������B
	gameplay->field->printpoints();
   //�X�y�[�X��������Ă���menu�ɑJ��
	if(Framework::instance().isKeyOn(' ')){
		gameplay->next = new menu(); return;
	}
	//��ʉ��ɏ���\��
	int i = Framework::instance().height();
	font::instance()->drawString(5,i/16-1,"press space to open menu");
	//������������menu�ɑJ��
	if(gameplay->field->point1 == gameplay->mMaxpoint || gameplay ->field->point2 == gameplay->mMaxpoint){
		gameplay->next = new menu();
		return;
	}
}
