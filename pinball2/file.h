#ifndef INCLUDED_FILE_H
#define INCLUDED_FILE_H
//�t�@�C����ǂݍ��݁A�f�[�^�����o���₷�����邽�߂̃N���X
class file{
public:
	file(char*filename);//�t�@�C��������͂���open����
	~file();
	unsigned getUnsigned(int pos);//pos�Ԗڂ�unsinged �����o���B
	char getBuffer(int pos);//pos�Ԗڂ�char �����o���B
	int getLength();
private:
	int size;
	char* buffer;
};
#endif;