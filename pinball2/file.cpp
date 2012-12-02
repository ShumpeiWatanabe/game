#include <fstream>
using namespace std;
#include "file.h"

file::file(char* filename):buffer(NULL){
	ifstream is(filename ,fstream::binary);
	//ファイルのopenに失敗したら死ぬ
	if(is.is_open()){;
	}
	else{
		exit(1);
	}
	is.seekg(0,ios::end);
	size = is.tellg();
	is.seekg(0,ios::beg);
	buffer = new char[size];
	is.read(buffer,size);

}

file::~file(){
	delete[] buffer;
	buffer = NULL;
}
unsigned file::getUnsigned(int pos){
	//ddsファイルを読みやすくする。色データはリトルエイディアンで格納されているのに注意
	const unsigned char* up;
	up = reinterpret_cast<const unsigned char* >(buffer+pos);
	unsigned ret = up[0];
	ret |= (up[1] << 8);
	ret |= (up[2] <<16);
	ret |= (up[3] <<24);
	return ret;
}

int file::getLength(){
	return(size);
}

char file::getBuffer(int pos){
	return(buffer[pos]);
}