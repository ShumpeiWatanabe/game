#include "map.h"
#include "image.h"
#include "GameLib/Framework.h"
using namespace GameLib;
/*•Ç‚ÆƒS[ƒ‹‚ÌŠG‚ðŽ‚Á‚Ä‚¢‚éƒNƒ‰ƒX*/

map::map(){
	int wid = Framework::instance().width();
    int	hei =Framework::instance().height();
	pic[0] = new image(wid,16,0xff00ff00);
	pic[1] = new image(16,hei-32,0xff0000ff);
}

void map::draw(){
	int wid = Framework::instance().width();
	int hei = Framework::instance().height();
	pic[0]->draw(0,0,0,0,pic[0]->mWidth,pic[0]->mHeight);
	pic[0]->draw(0,hei-16,0,0,pic[0]->mWidth,pic[0]->mHeight);
	pic[1]->draw(0,16,0,0,pic[1]->mWidth,pic[1]->mHeight);
	pic[1]->draw(wid-16,16,0,0,pic[1]->mWidth,pic[1]->mHeight);
}