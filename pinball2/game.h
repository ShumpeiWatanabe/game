#ifndef INCLUDED_GAME_H
#define INCLUDED_GAME_H
#include "base.h"
#include "State.h"
//�Q�[���������ׂĕێ����Ă���
//play ,menu,��Ԃ̕ێ��A������s��
class game : public base{

public:
	game(int max);
	~game(void);
	void update(base*);//�Q�[���𖈃t���[���X�V����
	void reset(void);//�Q�[��������������B
	State* field; //�Q�[����������
	base* now;
	base* next;
	int mMaxpoint;
};

#endif;