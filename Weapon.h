#ifndef WEAPON_H__
#define WEAPON_H__

class cWeapon
{
private:

public : 
	Sprite	m_Sprite;
	bool	m_bDead;
	bool	m_bDead2;

	cWeapon() 
	{};
	~cWeapon()
	{};

	void init(Vector2f	m_CharacterPos)//�ʱ�ȭ
	{
		m_bDead=false; //���� ��ü ������ ���ֱ�����
		
		if(g_Extern.wRan1 == 0)
		{
			m_Sprite.init("Image/w1l.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(50,50);	
			m_Sprite.m_pos = m_CharacterPos;
		}
		if(g_Extern.wRan1 == 1)
		{
			m_Sprite.init("Image/w2l.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(60,60);
			m_Sprite.m_pos = m_CharacterPos;
		}
		if(g_Extern.wRan1 == 2)
		{
			m_Sprite.init("Image/w3l.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(70,70);		
			m_Sprite.m_pos = m_CharacterPos;
		}
		if(g_Extern.wRan1 == 3)
		{
			m_Sprite.init("Image/w4l.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(80,80);		
			m_Sprite.m_pos = m_CharacterPos;
		}

	}

	void Release()//�޸� �ʱ�ȭ,�� ��
	{
		m_Sprite.Release();
	}

	void Render()//�׸���
	{
		m_Sprite.Render();
	}

	void FrameMove()
	{
		m_Sprite.m_pos.x+=20;
		if(m_Sprite.m_pos.x>=g_Extern.WINDOWSIZE_WIDTH)
		{
			m_bDead=true;
		}
	}
};
#endif