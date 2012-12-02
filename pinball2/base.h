#ifndef INCLUDED_BASE_H
#define INCLUDED_BASE_H
//ゲームの遷移を担当するクラスはすべてこのクラスを継承する。

class base{
public:
	base();
	~base();
	virtual void update(base* parent) = 0;//最終的にこれをCallすればよいようにする


};

#endif;