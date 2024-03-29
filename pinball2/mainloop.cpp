#include "mainloop.h"
#include "top.h"
#include "font.h"
void mainloop::update(base* kore){
	
	now->update(this);

	if(next != now){
		delete now;//もし、遷移が起こった場合はnextに次の遷移さきが書き込まれている。
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
