#ifndef CHARACTER_H__//class단점 자기들끼리 못찾음!so 이렇게 정의 내려줘야함! 히어로 클래스에서 STAGE_H__똑같이 쓰면 무시됨.
#define CHARACTER_H__//#ifndef와 #define 뒤에 이름은 같아야함.

class cCharacter
{
private:

public : 
	vector<cWeapon> m_WeaponList;
	vector<cWeapon2> m_WeaponList2;

	vector<cHp> m_HpList;
	vector<cHp2> m_HpList2;

	int			HP1;
	int			HP2;

	Sprite		m_Sprite;
	Sprite		m_Sprite2;

	Vector2f	m_Pos;
	Vector2f	m_Pos2;

	bool		m_DownKey1;
	bool		m_DownKey2;

	cCharacter() 
	{};
	~cCharacter()
	{};

	void onAddWeapon()
	{
		cWeapon a;
		a.init(m_Pos+m_Sprite.m_size/2);
		m_WeaponList.push_back(a);
	}
	void onAddWeapon2()
	{
		cWeapon2 b;
		b.init(m_Pos2+m_Sprite2.m_size/2);
		m_WeaponList2.push_back(b);
	}

	void init()//초기화
	{
		for(int i=0;i<4;i++)
		{
			cHp h;
			h.init(i*40);
			m_HpList.push_back(h);
		}
		for(int i=0;i<4;i++)
		{
			cHp2 h2;
			h2.init(i*40);
			m_HpList2.push_back(h2);
		}

		m_DownKey1=false;
		m_DownKey2= false;

		if(g_Extern.cRan1 == 0)
		{
			m_Sprite.init("Image/1.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(110,130);
			m_Pos = m_Sprite.m_pos;
		}
		if(g_Extern.cRan1 == 1)
		{
			m_Sprite.init("Image/2.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(150,150);
			m_Pos = m_Sprite.m_pos;
		}

		if(g_Extern.cRan1 == 2)
		{
			m_Sprite.init("Image/3.png");
			m_Sprite.m_Color=Color4f(1,1,1,1);
			m_Sprite.m_size=Vector2f(150,150);
			m_Pos = m_Sprite.m_pos;
		}
		
		if(g_Extern.cRan2 == 0)
		{
			m_Sprite2.init("Image/1r.png");
			m_Sprite2.m_Color=Color4f(1,1,1,1);
			m_Sprite2.m_size=Vector2f(150,150);
		}
		if(g_Extern.cRan2 == 1)
		{
			m_Sprite2.init("Image/2r.png");
			m_Sprite2.m_Color=Color4f(1,1,1,1);
			m_Sprite2.m_size=Vector2f(150,150);
		}
		if(g_Extern.cRan2 == 2)
		{
			m_Sprite2.init("Image/3r.png");
			m_Sprite2.m_Color=Color4f(1,1,1,1);
			m_Sprite2.m_size=Vector2f(150,150);
		}

		m_Sprite2.m_pos = Vector2f(g_Extern.WINDOWSIZE_WIDTH-150,g_Extern.WINDOWSIZE_HEIGHT+200);
		m_Pos2 = m_Sprite2.m_pos;

		HP1 = 4;
		HP2 = 4;
	}

	void Release()//메모리 초기화,끌 때
	{
		for(int i=0;i<m_HpList.size();i++)
		{
			m_HpList[i].Release();
		}
		m_HpList.clear();

		for(int i=0;i<m_HpList2.size();i++)
		{
			m_HpList2[i].Release();
		}
		m_HpList2.clear();

		m_Sprite.Release();
		m_Sprite2.Release();

		for(int i=0;i<m_WeaponList.size();i++)
		{
			m_WeaponList[i].Release();
		}
		m_WeaponList.clear();

		for(int i=0;i<m_WeaponList2.size();i++)
		{
			m_WeaponList2[i].Release();
		}
		m_WeaponList2.clear();
	}

	void Render()//그리기
	{
		for(int i=0;i<m_HpList.size();i++)
		{
			m_HpList[i].Render();
		}
		for(int i=0;i<m_HpList2.size();i++)
		{
			m_HpList2[i].Render();
		}
		for(int i=0;i<m_WeaponList.size();i++)
		{
			m_WeaponList[i].Render();
		}
		for(int i=0;i<m_WeaponList2.size();i++)
		{
			m_WeaponList2[i].Render();
		}
		m_Sprite.Render();
		m_Sprite2.Render();
	}

	void FrameMove()//키보드 입력,마우스 좌표 지정(?),계산하기
	{
		float Speed = 20;

		if(KeyDown('W')||KeyDown('w'))
		{
			m_Pos.y-=Speed;
		}
		if(KeyDown('S')||KeyDown('s'))
		{
			m_Pos.y+=Speed;
		}
		if(KeyDown('D'))
		{
			if(m_DownKey1==false)
				m_DownKey1=true;
		}

		if(KeyUp('D'))
		{
			if(m_DownKey1==true)
			{
				onAddWeapon();
				m_DownKey1=false;
			}
		}


		if(KeyDown(VK_UP))
		{
			m_Pos2.y-=Speed;
		}
		if(KeyDown(VK_DOWN))
		{
			m_Pos2.y+=Speed;
		}
		if(KeyDown(VK_LEFT))
		{
			if(m_DownKey2==false)
				m_DownKey2=true;
		}

		if(KeyUp(VK_LEFT))
		{
			if(m_DownKey2==true)
			{
				onAddWeapon2();
				m_DownKey2=false;
			}
		}

		if(m_Pos.y<=100)
			m_Pos.y=100;
		if(m_Pos.y>(g_Extern.WINDOWSIZE_HEIGHT-m_Sprite.m_size.y-50))
			m_Pos.y=g_Extern.WINDOWSIZE_HEIGHT-m_Sprite.m_size.y-50;
		m_Sprite.m_pos=m_Pos;

		if(m_Pos2.y<=100)
			m_Pos2.y=100;
		if(m_Pos2.y>(g_Extern.WINDOWSIZE_HEIGHT-m_Sprite.m_size.y-50))
			m_Pos2.y=g_Extern.WINDOWSIZE_HEIGHT-m_Sprite.m_size.y-50;
		m_Sprite2.m_pos=m_Pos2;

		for(int i=0;i<m_WeaponList.size();i++)
		{
			m_WeaponList[i].FrameMove();
		}

		for(int i=m_WeaponList.size()-1;i>=0;i--)
		{
			if(m_WeaponList[i].m_bDead==true)
			{
				m_WeaponList.erase(m_WeaponList.begin()+i);
			}
		}

		for(int i=0;i<m_WeaponList2.size();i++)
		{
			m_WeaponList2[i].FrameMove();
		}

		for(int i=m_WeaponList2.size()-1;i>=0;i--)
		{
			if(m_WeaponList2[i].m_bDead==true)
			{
				m_WeaponList2.erase(m_WeaponList2.begin()+i);
			}
		}
	}
};

#endif