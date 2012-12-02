#ifndef INCLUDED_CIRCLE_H
#define INCLUDED_CIRCLE_H
#include "image.h"
//�{�[����̌`�̕��̂̏���ێ�����B���[���h���W�Ƃ̓s�N�Z�����W��1000�{�ɂȂ��Ă���Ƃ���B
class Circle{
public:
	Circle(int radius//���a
		,int worldx//����x���W
		,int worldy//����y���W
		, int mass//�d��
		, int mvx//����x���x
		,int mvy//����y���x
		,char* filename);//�G�̃f�[�^�̖��O
	virtual ~Circle(void);

	int mRadius;
	int mWorldx;
	int mWorldy;
	int mMass;
	int mVx;
	int mVy;
	bool isIntersected(const Circle& ball)const;//�ق��̃{�[���ƏՓˏ�Ԃł��邩�ǂ����`�F�b�N
	virtual void attacked(Circle* ball);//�Փˏ���
	void draw(void);//����������
	virtual void move(void);//�����̃��[���h���W�ɑ��x�𑫂��B
	image* pic;
	bool ispenetrated[5];//�����������݂ǂ̃{�[���ƏՓˏ�Ԃɂ��邩�ǂ����`�F�b�N����z��ispenetrated[i]=true
	//���Ǝ�����i�ƏՓ˂��Ă���Ƃ������ƁB

};

#endif;