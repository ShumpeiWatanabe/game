#ifndef INCLUDED_MAINLOOP_H
#define INCLUDED_MAINLOOP_H
#include "base.h"
//top ‚Ü‚½‚Ígame ‚Ü‚½‚Íconfig ‚Ì‚Ç‚ê‚©‚Ìó‘Ô‚ğ•Û
class mainloop:public base{
public:
	mainloop();
	~mainloop();
	void update(base* kore);
	base* next;
	base* now;
	int maxpoint;

};

#endif;