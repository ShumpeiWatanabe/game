#ifndef INCLUDED_FONT_H
#define INCLUDED_FONT_H
/*������`�悷�邽�߂̃N���X
�V���O���g���łЂƂ����ł��Ȃ��悤�ɂȂ��Ă���B*/
class image;
class font{
public:
	static font* instance();
	void drawString(int x, int y, const char* string);//x�s��y��ɏ���
	static void create(char* filename);
	static void destroy();
private:
	font(char* filename);//�R���X�g���N�^�j�~
	font(const font&);//�R�s�[�R���X�g���N�^�j�~
	~font();
	image* mfonts;
	static font* mInstance;
};
#endif;