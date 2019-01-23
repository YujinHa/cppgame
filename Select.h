#ifndef SELECT_H__
#define SELECT_H__

class cSelect
{
private:
	Sprite		m_Sprite1;

	Sprite		m_Sprite7;
	Sprite		m_Sprite[3];
	Sprite		m_Sprite2[4];
	Sprite		m_Sprite3[3];
	Sprite		m_Sprite4[3];
	Sprite		m_Sprite5[4];
	Sprite		m_Sprite6[3];

	Vector2f	m_Pos;
	int temp;

	float		m_ftime;
	int			m_nSelectId;
	int			m_nSelectId2;
	int			m_nSelectId3;
	int			m_nSelectId4;
	int			m_nSelectId5;
	int			m_nSelectId6;

	bool		m_bSelect;
	bool		m_bSelect2;
	bool		m_bSelect3;
	bool		m_bSelect4;
	bool		m_bSelect5;
	bool		m_bSelect6;
public:

	cSelect()
	{}
	~cSelect()
	{}

	void init()
	{
		m_Sprite1.init("Image/select_bg.png");
		m_Sprite1.m_size=Vector2f(g_Extern.WINDOWSIZE_WIDTH,g_Extern.WINDOWSIZE_HEIGHT);//윈도우 창 크기 맞게

		PlaySound(L"Sound/lottery.wav",NULL,SND_ASYNC|SND_LOOP);

		m_bSelect =false;
		m_bSelect2 =false;
		m_bSelect3 =false;
		m_bSelect4 =false;
		m_bSelect5 =false;
		m_bSelect6 =false;

		m_Sprite7.init("Image/select_bg.png");

		for(int i=0; i<3;i++)
		{
			char name[255];
			sprintf(name,"Image/s1-%d.png",i+1);
			m_Sprite[i].init(name);
			m_Sprite[i].m_size=Vector2f(650,270);
			m_Sprite[i].m_pos=Vector2f(0,70);
		}
		for(int i=0; i<4;i++)
		{
			char name[255];
			sprintf(name,"Image/s2-%d.png",i+1);
			m_Sprite2[i].init(name);
			m_Sprite2[i].m_size=Vector2f(650,270);
			m_Sprite2[i].m_pos=Vector2f(0,340);
		}
		for(int i=0; i<3;i++)
		{
			char name[255];
			sprintf(name,"Image/s3-%d.png",i+1);
			m_Sprite3[i].init(name);
			m_Sprite3[i].m_size=Vector2f(650,270);
			m_Sprite3[i].m_pos=Vector2f(0,610);
		}

		for(int i=0; i<3;i++)
		{
			char name[255];
			sprintf(name,"Image/s4-%d.png",i+1);
			m_Sprite4[i].init(name);
			m_Sprite4[i].m_size=Vector2f(650,270);
			m_Sprite4[i].m_pos=Vector2f(650,70);
		}
		for(int i=0; i<4;i++)
		{
			char name[255];
			sprintf(name,"Image/s5-%d.png",i+1);
			m_Sprite5[i].init(name);
			m_Sprite5[i].m_size=Vector2f(650,270);
			m_Sprite5[i].m_pos=Vector2f(650,340);
		}
		for(int i=0; i<3;i++)
		{
			char name[255];
			sprintf(name,"Image/s6-%d.png",i+1);
			m_Sprite6[i].init(name);
			m_Sprite6[i].m_size=Vector2f(650,270);
			m_Sprite6[i].m_pos=Vector2f(650,610);
		}
		m_ftime=0;
		m_nSelectId=0;
		m_nSelectId2=0;
		m_nSelectId3=0;
		m_nSelectId4=0;
		m_nSelectId5=0;
		m_nSelectId6=0;
	}

	void Release()
	{
		m_Sprite1.Release();
		PlaySound(NULL,NULL,SND_ASYNC|SND_LOOP);

		for(int i=0; i<3;i++)
		{
			m_Sprite[i].Release();
		}
		for(int i=0; i<4;i++)
		{
			m_Sprite2[i].Release();
		}
		for(int i=0; i<3;i++)
		{
			m_Sprite3[i].Release();
		}
		for(int i=0; i<3;i++)
		{
			m_Sprite4[i].Release();
		}
		for(int i=0; i<4;i++)
		{
			m_Sprite5[i].Release();
		}
		for(int i=0; i<3;i++)
		{
			m_Sprite6[i].Release();
		}
	}

	void Render()
	{
		m_Sprite1.Render();

		if(m_bSelect==false)
		{
			int  t = (int)m_ftime%3;
			m_Sprite[t].Render();
		}
		else
			m_Sprite[m_nSelectId].Render();

		if(m_bSelect2==false)
		{
			int  t = (int)m_ftime%4;
			m_Sprite2[t].Render();
		}
		else
			m_Sprite2[m_nSelectId2].Render();

		if(m_bSelect3==false)
		{
			int  t = (int)m_ftime%3;
			m_Sprite3[t].Render();
		}
		else
			m_Sprite3[m_nSelectId3].Render();

		if(m_bSelect4==false)
		{
			int  t = (int)m_ftime%3;
			m_Sprite4[t].Render();
		}
		else
			m_Sprite4[m_nSelectId4].Render();

		if(m_bSelect5==false)
		{
			int  t = (int)m_ftime%4;
			m_Sprite5[t].Render();
		}
		else
			m_Sprite5[m_nSelectId5].Render();

		if(m_bSelect6==false)
		{
			int  t = (int)m_ftime%3;
			m_Sprite6[t].Render();
		}
		else
			m_Sprite6[m_nSelectId6].Render();
	}

	void FrameMove()
	{
		if(KeyDown(VK_SPACE))
		{
			g_Extern.g_nSceneNum=2;
		}

		m_ftime+=0.1;		
		for(int i=0; i<3;i++)
		{
			//m_Sprite[i].m_size=Vector2f(g_Extern.WINDOWSIZE_WIDTH,g_Extern.WINDOWSIZE_HEIGHT);
		}
		if(KeyDown('1'))
		{
			if(m_bSelect==false)
			{
				m_nSelectId = (int)m_ftime%3;
				g_Extern.cRan1 = m_nSelectId;
			}
			m_bSelect=true;
		}
		if(KeyDown('2'))
		{
			if(m_bSelect2==false)
			{
				m_nSelectId2 = (int)m_ftime%4;
				g_Extern.wRan1 = m_nSelectId2;
			}
			m_bSelect2=true;
		}
		if(KeyDown('3'))
		{
			if(m_bSelect3==false)
			{
				m_nSelectId3 = (int)m_ftime%3;
				g_Extern.iRan1 = m_nSelectId3;
			}
			m_bSelect3=true;
		}
		if(KeyDown('4'))
		{
			if(m_bSelect4==false)
			{
				temp = (int)m_ftime%3;
			
				if(m_nSelectId==temp)
				{
					temp = (temp+1)%3;
				}

				m_nSelectId4  = temp;
				g_Extern.cRan2 = m_nSelectId4;
			}
			m_bSelect4=true;
		}
		if(KeyDown('5'))
		{
			if(m_bSelect5==false)
			{
				m_nSelectId5 = (int)m_ftime%4;
				g_Extern.wRan2 = m_nSelectId5;
			}
			m_bSelect5=true;
		}
		if(KeyDown('6'))
		{
			if(m_bSelect6==false)
			{
				m_nSelectId6 = (int)m_ftime%3;
				g_Extern.iRan2 = m_nSelectId6;
			}
			m_bSelect6=true;
		}
	}
};

#endif