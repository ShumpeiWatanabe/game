#ifndef INCLUDED_PLAY_H
#define INCLUDED_PLAY_H
#include "base.h"
//���ۂɗV�ԂƂ��ɌĂ΂�Ă���N���X
//���j���[��ʂւ̕�����s��
class play : public base{
public:
	play();
	~play();
	void update(base* parent);//�Q�[�������̃t���[����Ԃɂ���A�`�悷��Ȃǂ̊֐����Ăяo���B

};

#endif;