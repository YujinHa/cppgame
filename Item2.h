#ifndef ITEM2_H__//class단점 자기들끼리 못찾음!so 이렇게 정의 내려줘야함! 히어로 클래스에서 STAGE_H__똑같이 쓰면 무시됨.
#define ITEM2_H__//#ifndef와 #define 뒤에 이름은 같아야함.
#include<time.h>

class cItem2
{
private:

public :
	Sprite	m_Sprite;
	bool	m_bDead;

	cItem2() 
	{};
	~cItem2()
	{};


	void init()//초기화
	{
		m_bDead=false;

		if(g_Extern.iRan2 == 0)
		{
			m_Sprite.init("Image/i1r.png");
			m_Sprite.m_size=Vector2f(150,150);
			m_Sprite.m_pos = Vector2f(g_Extern.WINDOWSIZE_WIDTH-300,rand()%(g_Extern.WINDOWSIZE_HEIGHT+200)-100);
		}
		if(g_Extern.iRan2 == 1)
		{
			m_Sprite.init("Image/i2r.png");
			m_Sprite.m_size=Vector2f(150,150);
			m_Sprite.m_pos = Vector2f(g_Extern.WINDOWSIZE_WIDTH-300,rand()%(g_Extern.WINDOWSIZE_HEIGHT+200)-100);
		}
		if(g_Extern.iRan2 == 2)
		{
			m_Sprite.init("Image/i3r.png");
			m_Sprite.m_size=Vector2f(150,150);
			m_Sprite.m_pos = Vector2f(g_Extern.WINDOWSIZE_WIDTH-300,rand()%(g_Extern.WINDOWSIZE_HEIGHT+200)-100);
		}
	
		if(m_Sprite.m_pos.y<=100)
			m_Sprite.m_pos.y=100;
		if(m_Sprite.m_pos.y>(g_Extern.WINDOWSIZE_HEIGHT-m_Sprite.m_size.y-50))
			m_Sprite.m_pos.y=g_Extern.WINDOWSIZE_HEIGHT-m_Sprite.m_size.y-50;
	}

	void Release()//메모리 초기화,끌 때
	{
		m_Sprite.Release();
	}

	void Render()//그리기
	{
		m_Sprite.Render();
	}
	void FrameMove()//키보드 입력,마우스 좌표 지정(?),계산하기
	{
	}

};

#endif