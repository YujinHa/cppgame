/*#ifndef SELECTBACKGROUND_H__//class���� �ڱ�鳢�� ��ã��!so �̷��� ���� ���������! ����� Ŭ�������� STAGE_H__�Ȱ��� ���� ���õ�.
#define SELECTBACKGROUND_H__//#ifndef�� #define �ڿ� �̸��� ���ƾ���.

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

	void init()//�ʱ�ȭ
	{
		m_Sprite1.init("Image/select_bg.png");
		m_Sprite1.m_size=Vector2f(g_Extern.WINDOWSIZE_WIDTH,g_Extern.WINDOWSIZE_HEIGHT);//������ â ũ�� �°�
	}

	void Release()//�޸� �ʱ�ȭ,�� ��
	{
		m_Sprite1.Release();
	}

	void Render()//�׸���
	{
		m_Sprite1.Render();//����� �� ���� ����
	}

	void FrameMove()//Ű���� �Է�,���콺 ��ǥ ����(?),����ϱ�
	{
	}
};

#endif*/