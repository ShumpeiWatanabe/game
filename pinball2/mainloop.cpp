#include "mainloop.h"
#include "top.h"
#include "font.h"
void mainloop::update(base* kore){
	
	now->update(this);

	if(next != now){
		delete now;//�����A�J�ڂ��N�������ꍇ��next�Ɏ��̑J�ڂ������������܂�Ă���B
		now = next;
	}
	
}

mainloop::mainloop():maxpoint(20){
	now  = new top();
	font::create("picture/font_b.dds");
	next = now;
}

mainloop::~mainloop(){
	delete now;
	now = 0;
	next = 0;
}
