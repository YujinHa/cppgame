#ifndef ITEM2_H__//class���� �ڱ�鳢�� ��ã��!so �̷��� ���� ���������! ����� Ŭ�������� STAGE_H__�Ȱ��� ���� ���õ�.
#define ITEM2_H__//#ifndef�� #define �ڿ� �̸��� ���ƾ���.
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


	void init()//�ʱ�ȭ
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

	void Release()//�޸� �ʱ�ȭ,�� ��
	{
		m_Sprite.Release();
	}

	void Render()//�׸���
	{
		m_Sprite.Render();
	}
	void FrameMove()//Ű���� �Է�,���콺 ��ǥ ����(?),����ϱ�
	{
	}

};

#endif