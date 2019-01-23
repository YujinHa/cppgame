/*#ifndef SELECTBACKGROUND_H__//class단점 자기들끼리 못찾음!so 이렇게 정의 내려줘야함! 히어로 클래스에서 STAGE_H__똑같이 쓰면 무시됨.
#define SELECTBACKGROUND_H__//#ifndef와 #define 뒤에 이름은 같아야함.

class cSelectBackground
{
private:
	Sprite		m_Sprite1;
	Vector2f	m_Pos;

public : 
	cSelectBackground() 
	{};
	~cSelectBackground()
	{};

	void init()//초기화
	{
		m_Sprite1.init("Image/select_bg.png");
		m_Sprite1.m_size=Vector2f(g_Extern.WINDOWSIZE_WIDTH,g_Extern.WINDOWSIZE_HEIGHT);//윈도우 창 크기 맞게
	}

	void Release()//메모리 초기화,끌 때
	{
		m_Sprite1.Release();
	}

	void Render()//그리기
	{
		m_Sprite1.Render();//배경을 맨 먼저 쓰기
	}

	void FrameMove()//키보드 입력,마우스 좌표 지정(?),계산하기
	{
	}
};

#endif*/