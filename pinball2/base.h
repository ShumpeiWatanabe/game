#ifndef INCLUDED_BASE_H
#define INCLUDED_BASE_H
//�Q�[���̑J�ڂ�S������N���X�͂��ׂĂ��̃N���X���p������B

class base{
public:
	base();
	~base();
	virtual void update(base* parent) = 0;//�ŏI�I�ɂ����Call����΂悢�悤�ɂ���


};

#endif;