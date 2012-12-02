#ifndef INCLUDED_FILE_H
#define INCLUDED_FILE_H
//ファイルを読み込み、データを取り出しやすくするためのクラス
class file{
public:
	file(char*filename);//ファイル名を入力してopenする
	~file();
	unsigned getUnsigned(int pos);//pos番目のunsinged を取り出す。
	char getBuffer(int pos);//pos番目のchar を取り出す。
	int getLength();
private:
	int size;
	char* buffer;
};
#endif;