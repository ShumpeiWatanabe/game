#ifndef INCLUDED_MAINLOOP_H
#define INCLUDED_MAINLOOP_H
#include "base.h"
//top �܂���game �܂���config �̂ǂꂩ�̏�Ԃ�ێ�
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