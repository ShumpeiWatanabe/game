#include "GameLib/Framework.h"
using namespace GameLib;
#include "menu.h"
#include "game.h"
#include "play.h"
#include "top.h"
#include "font.h"
void menu::update(base* parent){
	font::instance()->drawString(5,5,"reset r");//���̕\��
	font::instance()->drawString(5,6,"top t");
	font::instance()->drawString(5,7,"continue play c");
	game* gameplay = dynamic_cast<game*>(parent);
	//����������������Ă����炨�߂łƂ���\��
	if(gameplay->field->point1 == gameplay->mMaxpoint){
		font::instance()->drawString(5,4,"player1 congratulations!");
	}
	if(gameplay->field->point2 == gameplay->mMaxpoint){
		font::instance()->drawString(5,4,"player2 congratulations!");
	}
	//r�ŏ�����ԁB��������v���C�ɖ߂�
	if(Framework::instance().isKeyOn('r')){
		gameplay->reset();
		gameplay->next = new play();
		return;			
	}
	//����������top�ɖ߂�B�e��next�Ɏ��̑J�ڏꏊ���������ށB
	if(Framework::instance().isKeyOn('t')){
		gameplay->next = new top();
		return;
	}
	//c��������v���C�ĊJ�B
	if(Framework::instance().isKeyOn('c')){	
		gameplay->next = new play();
		return;
	}

}

menu::menu(){
}

menu::~menu(){
}
