#ifndef INCLUDED_IMAGE_H
#define INCLUDED_IMAGE_H
/*画像情報を保持、画面に書き込むためのクラス。クラスひとつにひとつの絵を持っている。*/
class image{
public:
	image(int width, int height,unsigned color);//単色の短冊を用意するためのコンストラクタ。
	image(char* filename);//画像ファイル名を入力して底の画像情報を保持するためのコンストラクタ。
	~image();
	//持っている画像を描画する。
	void draw( 
		int dstX, //書き込む画面のｘ座標
		int dstY, //書き込む画面のy座標
		int srcX, //絵のデータの書き始めのｘ座標
		int srcY, //絵のデータの書き始めのｙ座標
		int width, //部分の絵の横幅
		int height ) const;//一部分の絵の縦幅

	void draw();//これを呼び出すと、左上に絵を描画する。

	unsigned mWidth;//画像の横幅
	unsigned mHeight;//画像の横幅
	unsigned* picture;//何番目に何色があるかを保存する。
};
#endif;