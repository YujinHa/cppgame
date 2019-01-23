#ifndef WEAPON2_H__
#define WEAPON2_H__

class cWeapon2
{
private:

public : 
	Sprite	m_Sprite;
	bool	m_bDead;

	cWeapon2() 
	{};
	~cWeapon2()
	{};

	void init(Vector2f	m_CharacterPos)//초기화
	{
		m_bDead = false;

		if(g_Extern.wRan2 == 0)
		{
			m_Sprite.init("Image/w1.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(50,50);	
			m_Sprite.m_pos = m_CharacterPos;
		}
		if(g_Extern.wRan2 == 1)
		{
			m_Sprite.init("Image/w2.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(60,60);
			m_Sprite.m_pos = m_CharacterPos;
		}
		if(g_Extern.wRan2 == 2)
		{
			m_Sprite.init("Image/w3.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(70,70);		
			m_Sprite.m_pos = m_CharacterPos;
		}
		if(g_Extern.wRan2 == 3)
		{
			m_Sprite.init("Image/w4.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(80,80);		
			m_Sprite.m_pos = m_CharacterPos;
		}
	}

	void Release()//메모리 초기화,끌 때
	{
		m_Sprite.Release();
	}

	void Render()//그리기
	{
		m_Sprite.Render();
	}

	void FrameMove()
	{
		m_Sprite.m_pos.x-=20;
		if(m_Sprite.m_pos.x<=0)
		{
			m_bDead=true;
		}
	}
};
#endif