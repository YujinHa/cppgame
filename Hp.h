#ifndef HP_H__//class���� �ڱ�鳢�� ��ã��!so �̷��� ���� ���������! ����� Ŭ�������� STAGE_H__�Ȱ��� ���� ���õ�.
#define HP_H__//#ifndef�� #define �ڿ� �̸��� ���ƾ���.

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

	void init(int a)//�ʱ�ȭ
	{
		m_Sprite.init("Image/HP.png");
		m_Sprite.m_size=Vector2f(40,40);//������ â ũ�� �°�
		m_Sprite.m_pos = Vector2f(a,0);
		m_Pos = m_Sprite.m_pos;
	}

	void Release()//�޸� �ʱ�ȭ,�� ��
	{
		m_Sprite.Release();

	}

	void Render()//�׸���
	{
		m_Sprite.Render();//����� �� ���� ����

	}

	void FrameMove()//Ű���� �Է�,���콺 ��ǥ ����(?),����ϱ�
	{
	}
};

#endif