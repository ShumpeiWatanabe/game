#include "GameLib/Framework.h"
#include "mainloop.h"
using namespace GameLib;
int i = 0;
mainloop* mloop;
/*Framework::update()���ꂪ���t���[���Ă΂��B���̒��g���������Ƃ��S�̂Ƃ��Ă̖ڕW*/
void Framework::update(){
	if(i == 0){
		mloop = new mainloop();//���[�v�̒��g��mainloop�Ɋۓ���
		i++;
	}
	else{
		mloop->update(mloop);
	}
}
