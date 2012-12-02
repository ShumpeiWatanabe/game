#ifndef INCLUDED_STATE_H
#define INCLUDED_STATE_H
#include "base.h"
#include "Circle.h"
#include "image.h"
#include "map.h"
#include "GameLib/Framework.h"

/*�Q�[���̃f�[�^�͂��ׂĂ����ŊǗ�����B
�Q�[�����X�V
�Q�[����`��
���_�v�Z*/
class State{
public:
	State();
	~State();

	void renew(void);//�Q�[����Ԃ̍X�V�@���͂��L���b�`���ăQ�[�������̃t���[���̏�Ԃɂ���B
	void draw(void);//�Q�[����`�悷��B
	void printpoints(void);//�v���[���[�̓��_��`�悷��B
	void reset(void);//�{�[���̈ʒu�Ɠ��_������������B
	int point1;//�v���C���[�P�̓��_������
	int point2;//�v���C���[2�̓��_������

private:
	Circle* packs[5];//2�̃o�b�g��3�̃{�[��������
	map* mMap;//�ǂƃS�[���̊G������
	image* background;//�w�i�̊G������


};
#endif;