#ifndef INCLUDED_CONFIG_H
#define INCLUDED_CONFIG_H
#include "base.h"
//�Q�[���̐ݒ������N���X�B�I���Ǝ����I��top��ʂւƑJ�ڂ���
class config : public base{
public:
	config();
	~config();
	void update(base* parent);
};
#endif;