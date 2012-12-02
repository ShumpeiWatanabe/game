#ifndef INCLUDED_FONT_H
#define INCLUDED_FONT_H
/*文字を描画するためのクラス
シングルトンでひとつしかできないようになっている。*/
class image;
class font{
public:
	static font* instance();
	void drawString(int x, int y, const char* string);//x行目y列に書く
	static void create(char* filename);
	static void destroy();
private:
	font(char* filename);//コンストラクタ阻止
	font(const font&);//コピーコンストラクタ阻止
	~font();
	image* mfonts;
	static font* mInstance;
};
#endif;