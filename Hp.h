#ifndef HP_H__//class단점 자기들끼리 못찾음!so 이렇게 정의 내려줘야함! 히어로 클래스에서 STAGE_H__똑같이 쓰면 무시됨.
#define HP_H__//#ifndef와 #define 뒤에 이름은 같아야함.

class cHp
{
private:
	Sprite		m_Sprite;

	Vector2f	m_Pos;


public : 
	cHp() 
	{};
	~cHp()
	{};

	void init(int a)//초기화
	{
		m_Sprite.init("Image/HP.png");
		m_Sprite.m_size=Vector2f(40,40);//윈도우 창 크기 맞게
		m_Sprite.m_pos = Vector2f(a,0);
		m_Pos = m_Sprite.m_pos;
	}

	void Release()//메모리 초기화,끌 때
	{
		m_Sprite.Release();

	}

	void Render()//그리기
	{
		m_Sprite.Render();//배경을 맨 먼저 쓰기

	}

	void FrameMove()//키보드 입력,마우스 좌표 지정(?),계산하기
	{
	}
};

#endif