#ifndef ITEM_H__//class���� �ڱ�鳢�� ��ã��!so �̷��� ���� ���������! ����� Ŭ�������� STAGE_H__�Ȱ��� ���� ���õ�.
#define ITEM_H__//#ifndef�� #define �ڿ� �̸��� ���ƾ���.
#include<time.h>

class cItem
{
private:

public :
	Sprite	m_Sprite;
	bool	m_bDead;

	cItem() 
	{};
	~cItem()
	{};


	void init()//�ʱ�ȭ
	{
		m_bDead=false;

		if(g_Extern.iRan1 == 0)
		{
			m_Sprite.init("Image/i1l.png");
			m_Sprite.m_size=Vector2f(150,150);
			m_Sprite.m_pos = Vector2f(200,rand()%(g_Extern.WINDOWSIZE_HEIGHT+200)-100);
		}
		if(g_Extern.iRan1 == 1)
		{
			m_Sprite.init("Image/i2l.png");
			m_Sprite.m_size=Vector2f(150,150);
			m_Sprite.m_pos = Vector2f(200,rand()%(g_Extern.WINDOWSIZE_HEIGHT+200)-100);
		}
		if(g_Extern.iRan1 == 2)
		{
			m_Sprite.init("Image/i3l.png");
			m_Sprite.m_size=Vector2f(150,150);
			m_Sprite.m_pos = Vector2f(200,rand()%(g_Extern.WINDOWSIZE_HEIGHT+200)-100);
		}
	
		if(m_Sprite.m_pos.y<=100) // �̵����ɹ���
			m_Sprite.m_pos.y=100;
		if(m_Sprite.m_pos.y>(g_Extern.WINDOWSIZE_HEIGHT-m_Sprite.m_size.y-50))
			m_Sprite.m_pos.y=g_Extern.WINDOWSIZE_HEIGHT-m_Sprite.m_size.y-50;// 
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