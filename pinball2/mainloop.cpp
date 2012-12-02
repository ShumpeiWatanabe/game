#include "mainloop.h"
#include "top.h"
#include "font.h"
void mainloop::update(base* kore){
	
	now->update(this);

	if(next != now){
		delete now;//‚à‚µA‘JˆÚ‚ª‹N‚±‚Á‚½ê‡‚Ínext‚ÉŸ‚Ì‘JˆÚ‚³‚«‚ª‘‚«‚Ü‚ê‚Ä‚¢‚éB
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
