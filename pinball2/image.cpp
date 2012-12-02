#include "image.h"
#include "file.h"
#include "GameLib/Framework.h"

using namespace GameLib;

image::image(char *filename){
	file imagefile(filename);
	mWidth = imagefile.getUnsigned(16);
	mHeight = imagefile.getUnsigned(12);
	unsigned size = mWidth*mHeight;
	picture = new unsigned[size];
	for(unsigned i = 0; i < size; i++){
		picture[i] = imagefile.getUnsigned(128+4*i);
	}
}

image::image(int width, int height, unsigned color){
	mWidth = width;
	mHeight = height;
	unsigned size = width*height;
	picture = new unsigned[size];
	for(unsigned i = 0; i < size; i++){
		picture[i] = color;
	}
}

image::~image(){
	delete[] picture;
	picture = 0;
}

void image::draw(
int dstX,// ‰æ–Ê‚ÌxÀ•W
int dstY, //‰æ–Ê‚Ì‚™À•W
int srcX, //ŠG‚Ì‚˜À•W
int srcY, //ŠG‚Ì‚™À•W
int width, //ŠG‚Ì‘‚­‚Æ‚±‚ë‚Ì‰¡•Ac•
int height ) const {
	unsigned* vram = Framework::instance().videoMemory();
	int windowWidth = Framework::instance().width();
	int windowHeight = Framework::instance().height();
	for ( int y = 0; y < height; ++y ){
		for ( int x = 0; x < width; ++x ){
			if( y + dstY >windowHeight || x+ dstX > windowWidth){
				return;
			}
			unsigned src = picture[ ( y + srcY ) * mWidth + ( x + srcX ) ];
			unsigned* dst = &vram[ ( y + dstY ) * windowWidth + ( x + dstX ) ];
			unsigned srcA = ( src & 0xff000000 ) >> 24;
			unsigned srcR = src & 0xff0000;
			unsigned srcG = src & 0x00ff00;
			unsigned srcB = src & 0x0000ff;
			unsigned dstR = *dst & 0xff0000;
			unsigned dstG = *dst & 0x00ff00;
			unsigned dstB = *dst & 0x0000ff;
			unsigned r = ( srcR - dstR ) * srcA / 255 + dstR;
			unsigned g = ( srcG - dstG ) * srcA / 255 + dstG;
			unsigned b = ( srcB - dstB ) * srcA / 255 + dstB;

            *dst = ( r & 0xff0000 ) | ( g & 0x00ff00 ) | b;
		}
	}
}

void image::draw(){
	this->draw(0,0,0,0,this->mWidth,this->mHeight);
}
