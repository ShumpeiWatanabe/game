#ifndef INCLUDED_IMAGE_H
#define INCLUDED_IMAGE_H
/*�摜����ێ��A��ʂɏ������ނ��߂̃N���X�B�N���X�ЂƂɂЂƂ̊G�������Ă���B*/
class image{
public:
	image(int width, int height,unsigned color);//�P�F�̒Z����p�ӂ��邽�߂̃R���X�g���N�^�B
	image(char* filename);//�摜�t�@�C��������͂��Ē�̉摜����ێ����邽�߂̃R���X�g���N�^�B
	~image();
	//�����Ă���摜��`�悷��B
	void draw( 
		int dstX, //�������މ�ʂ̂����W
		int dstY, //�������މ�ʂ�y���W
		int srcX, //�G�̃f�[�^�̏����n�߂̂����W
		int srcY, //�G�̃f�[�^�̏����n�߂̂����W
		int width, //�����̊G�̉���
		int height ) const;//�ꕔ���̊G�̏c��

	void draw();//������Ăяo���ƁA����ɊG��`�悷��B

	unsigned mWidth;//�摜�̉���
	unsigned mHeight;//�摜�̉���
	unsigned* picture;//���Ԗڂɉ��F�����邩��ۑ�����B
};
#endif;