#include "GameLib/Framework.h"
#include "mainloop.h"
using namespace GameLib;
int i = 0;
mainloop* mloop;
/*Framework::update()これが毎フレーム呼ばれる。この中身を書くことが全体としての目標*/
void Framework::update(){
	if(i == 0){
		mloop = new mainloop();//ループの中身はmainloopに丸投げ
		i++;
	}
	else{
		mloop->update(mloop);
	}
}
