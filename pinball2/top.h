#ifndef INCLUDED_TOP_H
#define INCLUDED_TOP_H
#include "base.h"
#include "image.h"
//top��ʂ�\�����邽�߂̃N���X
//config ��game ��Ԃւ̕�����s��
class top : public base{
public:
	top(void);
	~top(void);
	void update(base*);

	image* pic;
};
#endif;