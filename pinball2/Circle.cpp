#include "Circle.h"
#include "image.h"
#include "GameLib/Framework.h"
#include "math.h"
using namespace GameLib;
//�Փ˔�����s���B�{�[�����m�̒��S�ԋ������A�{�[�����m�̔��a�̘a���A�Z����΂������Ă���B
bool Circle::isIntersected(const Circle &ball)const{
	int dx = (ball.mWorldx - mWorldx)/10;
	int dy = (ball.mWorldy - mWorldy)/10;
	int sum = (ball.mRadius + mRadius)/10;
	if(dx*dx + dy*dy <= sum*sum){
			return true;//�ځ[��Ƃ������Ă���Ƃ��ɂ�true����������
	}
	else{
		return false;//�������Ă��Ȃ��Ƃ��ɂ�false
	}
}
//�Փˏ���
	void Circle::attacked(Circle *ball){
		//�Փ˂���鑤�ƏՓ˂��鑤�̏���double�^�ɕϊ��B
	const double two = 2.0;
	double radius = mRadius;
	double worldx = mWorldx;
	double worldy = mWorldy;
	double mass = mMass;
	double vx = mVx;
	double vy = mVy;

	double bradius = ball->mRadius;
	double bworldx = ball->mWorldx;
	double bworldy = ball->mWorldy;
	double bmass = ball->mMass;
	double bvx = ball->mVx;
	double bvy = ball->mVy;
//��̉~�̒��S�Ԃ̋������o���B
	double dis = sqrt((bworldx - worldx)*(bworldx-worldx)+(bworldy-worldy)*(bworldy-worldy));
	//�Փ˂���鑤�Ƃ��鑤�̊p�x���o���B
	double cos = (bworldx -worldx)/dis;
	double sin = (bworldy- worldy)/dis;

	double xdash = cos*vx + sin*vy;//�Փ˂���鑤�́A�Փ˖ʂɐ����ȕ��̑��x�������o���B
	double ydash = sin*vx - cos*vy;//�Փ˂���鑤�́A�Փ˖ʂɕ��s�Ȃȕ��̑��x�������o���B

	double bxdash = cos*bvx + sin*bvy;////�Փ˂��鑤�́A�Փ˖ʂɐ����ȕ��̑��x�������o���B
	double bydash = sin*bvx - cos*bvy;//�Փ˂��鑤�́A�Փ˖ʂɐ����ȕ��̑��x�������o���B
//�^���ʕۑ����Ɣ����W���P�ɂ��A�Փ˖ʂɐ����Ȑ����̑��x�̏Փˌ�̑��x�����߂�B
	double afterxdash = (mass-bmass)/(mass+bmass)*xdash + two*bmass/(mass+bmass)*bxdash;
	double afterbxdash = afterxdash - bxdash + xdash;
//���߂����x�̂������@y���������߂�B
	double avx = cos*afterxdash + sin*ydash;
	double avy = sin*afterxdash - cos*ydash;

	double abvx = cos*afterbxdash + sin*bydash;
	double abvy = sin*afterbxdash - cos*bydash;
//�������ށB
	this->mVx = static_cast<int>(avx);
	this->mVy = static_cast<int>(avy);

	ball->mVx = static_cast<int>(abvx);
	ball->mVy = static_cast<int>(abvy);
	//��������ꍇ�͕␳
	if(this->mVx > 16000){
		this->mVx = 16000;
	}
	if(this->mVy > 16000){
		this->mVy = 16000;
	}
	if(this->mVx < -16000){
		this->mVx = -16000;
	}
	if(this->mVy < -16000){
		this->mVy = -16000;
	}
	if(ball->mVx > 16000){
		ball->mVx = 16000;
	}
	if(ball->mVy > 16000){
		ball->mVy = 16000;
	}
	if(ball->mVx < -16000){
		ball->mVx = -16000;
	}
	if(ball->mVy < -16000){
		ball->mVy = -16000;
	}
}
//������
Circle::Circle(int radius,int worldx, int worldy, int mass, int mvx, int mvy,char* filename){
	this->mRadius = radius;
	this->mWorldx = worldx;
	this->mWorldy = worldy;
	this->mMass = mass;
	this->mVx = mvx;
	this->mVy = mvy;
	pic = new image(filename);
	for(int i = 0; i< 5; i++){
		ispenetrated[i] = false;
	}
}

//�`��
void Circle::draw(){
	pic->draw(((mWorldx-mRadius)+500)/1000,((mWorldy-mRadius)+500)/1000,0,0,pic->mWidth,pic->mHeight);
}

Circle::~Circle(){
	delete pic;
	pic  = 0;
}

void Circle::move(void){
	mWorldx +=mVx;
	mWorldy +=mVy;
}



