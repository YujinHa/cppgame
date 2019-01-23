#include "Include.h"

cStage:: cStage()
{
}

cStage:: ~cStage()
{
}

void cStage:: init()
{
	PlaySound(L"Sound/fight.wav",NULL,SND_ASYNC|SND_LOOP);
	for(int i=0;i<4;i++)
	{
		cItem a;
		a.init();
		m_ItemList.push_back(a);
	}
	for(int i=0;i<4;i++)
	{
		cItem2 b;
		b.init();
		m_ItemList2.push_back(b);
	}

	m_pCharacter = new cCharacter();
	m_pCharacter->init();

	m_PlayMp4.init("Video/bg_1.mp4");
}

void cStage:: Release()//메모리 초기화
{
	for(int i=0;i<m_ItemList.size();i++)
	{
		m_ItemList[i].Release();
	}
	m_ItemList.clear();

	for(int i=0;i<m_ItemList2.size();i++)
	{
		m_ItemList2[i].Release();
	}
	m_ItemList2.clear();

	m_pCharacter->Release();
	delete m_pCharacter;

	PlaySound(NULL,NULL,SND_ASYNC|SND_LOOP);
	m_PlayMp4.Release();
}
void cStage:: FrameMove()//키보드 입력,마우스 좌표 지정(?)
{
	for(int i=0;i<m_ItemList2.size();i++)
	{
		m_ItemList2[i].FrameMove();
	}
	m_pCharacter->FrameMove();

	for(int i=0;i<m_ItemList2.size();i++)
	{
		if(m_ItemList2[i].m_bDead ==false) 
		{
			for(int j=0;j<m_pCharacter->m_WeaponList.size();j++)
			{
				if(m_pCharacter->m_WeaponList[j].m_bDead==false) // false 이면 총이 물체 맞으면 없어짐
				{
					Vector2f p1 = m_ItemList2[i].m_Sprite.m_pos+m_ItemList2[i].m_Sprite.m_size/2;
					Vector2f p2 = m_pCharacter->m_WeaponList[j].m_Sprite.m_pos+m_pCharacter->m_WeaponList[j].m_Sprite.m_size/2;

					Vector2f pt = p1-p2;
					if(pt.Length()<=70)//충돌
					{
						m_pCharacter->m_WeaponList[j].m_bDead=true;
						m_ItemList2[i].m_bDead = true;
					}
				}
			}
		}
	}

	for(int j=0;j<m_pCharacter->m_WeaponList.size();j++)
	{
		if(m_pCharacter->m_WeaponList[j].m_bDead==false)
		{
			Vector2f p3 = m_pCharacter->m_Sprite2.m_pos+m_pCharacter->m_Sprite2.m_size/2;
			Vector2f p4 = m_pCharacter->m_WeaponList[j].m_Sprite.m_pos+m_pCharacter->m_WeaponList[j].m_Sprite.m_size/2;

			Vector2f pt2 = p3-p4;
			if(pt2.Length()<=90)//충돌
			{
				m_pCharacter->m_WeaponList[j].m_bDead=true;
				m_pCharacter->HP2--;
				if(m_pCharacter->m_HpList2.size()!=0)
					m_pCharacter->m_HpList2.erase(m_pCharacter->m_HpList2.begin()+(m_pCharacter->m_HpList2.size()-1));
				if(m_pCharacter->HP2 == 0)
				{
					g_Extern.Win = g_Extern.cRan1;
					g_Extern.Lose = g_Extern.cRan2;
					//return;다음씬
					Sleep(1000);
					g_Extern.g_nSceneNum=3;
				}
			}
		}
	}
	for(int i=(m_ItemList2.size()-1);i>=0;i--) // item이 사라짐, 부딪히면
	{
		if(m_ItemList2[i].m_bDead == true)
		{
			m_ItemList2.erase(m_ItemList2.begin()+i);
		}
	}

	for(int i=0;i<m_ItemList.size();i++)
	{
		m_ItemList[i].FrameMove();
	}

	for(int i=0;i<m_ItemList.size();i++)
	{
		if(m_ItemList[i].m_bDead==false)
		{
			for(int j=0;j<m_pCharacter->m_WeaponList2.size();j++)
			{
				if(m_pCharacter->m_WeaponList2[j].m_bDead==false)
				{
					Vector2f p1 = m_ItemList[i].m_Sprite.m_pos+m_ItemList[i].m_Sprite.m_size/2;
					Vector2f p2 = m_pCharacter->m_WeaponList2[j].m_Sprite.m_pos+m_pCharacter->m_WeaponList2[j].m_Sprite.m_size/2;

					Vector2f pt = p1-p2;
					if(pt.Length()<=70)//충돌
					{
						m_pCharacter->m_WeaponList2[j].m_bDead=true;
						m_ItemList[i].m_bDead = true;
					}

				}
			}
		}
	}

	for(int j=0;j<m_pCharacter->m_WeaponList2.size();j++)
	{
		if(m_pCharacter->m_WeaponList2[j].m_bDead==false)
		{
			Vector2f p3 = m_pCharacter->m_Sprite.m_pos+m_pCharacter->m_Sprite.m_size/2;
			Vector2f p4 = m_pCharacter->m_WeaponList2[j].m_Sprite.m_pos+m_pCharacter->m_WeaponList2[j].m_Sprite.m_size/2;

			Vector2f pt2 = p3-p4;
			if(pt2.Length()<=90)//충돌
			{
				m_pCharacter->m_WeaponList2[j].m_bDead=true;
				m_pCharacter->HP1--;
				if(m_pCharacter->m_HpList.size()!=0)
					m_pCharacter->m_HpList.erase(m_pCharacter->m_HpList.begin()+(m_pCharacter->m_HpList.size()-1));
				if(m_pCharacter->HP1 == 0)
				{
					g_Extern.Win = g_Extern.cRan2;
					g_Extern.Lose = g_Extern.cRan1;
					//return; 다음씬
					Sleep(1000);
					g_Extern.g_nSceneNum=3;
				}
			}
		}
	}
	for(int i=(m_ItemList.size()-1);i>=0;i--)
	{
		if(m_ItemList[i].m_bDead == true)
		{
			m_ItemList.erase(m_ItemList.begin()+i);
		}
	}

	m_PlayMp4.m_size = Vector2f(g_Extern.WINDOWSIZE_WIDTH,g_Extern.WINDOWSIZE_HEIGHT);
	//item2
}

void cStage:: Render()
{
	m_PlayMp4.Render(10);
	for(int i=0;i<m_ItemList.size();i++)
	{
		m_ItemList[i].Render();
	}
	for(int i=0;i<m_ItemList2.size();i++)
	{
		m_ItemList2[i].Render();
	}
	m_pCharacter->Render();
}