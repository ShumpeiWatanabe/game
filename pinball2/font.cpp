#include "font.h"
#include "image.h"
#include "GameLib/Framework.h"
using namespace GameLib;

font* font::mInstance = 0;

font::font(char* filename ):mfonts(0){
	this->mfonts = new image(filename);//�����̊G���K������B
}

font::~font(){
	delete this->mfonts;
	mfonts = 0;
}

font* font::instance(){
	return mInstance;
}

void font::create(char *filename){
		STRONG_ASSERT(!mInstance && "��������ʖ�");
		mInstance = new font(filename);
}

void font::destroy(){
	delete mInstance;
	mInstance = 0;
}

void font::drawString(int x, int y, const char* string){
	const int wid = 8;
	const int hei = 16;
	int dstX = x*8;
	int dstY = y*16;
	if(dstY < 0 || dstY > Framework::instance().height()){
		return;//�͈͂���E���Ă���ΏI��
	}
	for( int i = 0; string[i] != '\0';i++){//�����𒣂�B�A�X�L�[�R�[�h�ƕ����̊G��Ή�������B
		if(dstX < 0 || dstX >Framework::instance().width()){
			return;
		}
		char tmp = string[i];
		tmp -= 32;
		if(tmp < 0 || tmp > 95){
			tmp = 95;
		}
		int srcX = tmp%16*wid;
		int srcY = tmp/16*hei;
		this->mfonts->draw(dstX,dstY,srcX,srcY,wid,hei);
		dstX += wid;
	}
}
