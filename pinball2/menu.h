#ifndef INCLUDED_MENU_H
#define INCLUDED_MENU_H
#include "base.h"
//���j���[��ʂ�ێ����Ă����B�Q�[���ĊJ�@top��ʂɖ߂�@������Ԃɖ߂� �̕�����s��
class menu : public base{
public:
	menu();
	~menu();
	void update(base* parent);
};

#endif;
