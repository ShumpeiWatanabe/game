#ifndef INCLUDED_MAP_H
#define INCLUDED_MAP_H
#include "image.h"
/*�ǂƃS�[���̊G�����������Ă���N���X�B*/
class map{
public:
	map();
	~map(void);

	void draw(void);//�ǂƃS�[����`�悷��B

	image* pic[2];//�ǂƃS�[���̊G��ێ�
	
};
#endif;