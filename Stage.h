#ifndef STAGE_H__//class���� �ڱ�鳢�� ��ã��!so �̷��� ���� ���������! ����� Ŭ�������� STAGE_H__�Ȱ��� ���� ���õ�.
#define STAGE_H__//#ifndef�� #define �ڿ� �̸��� ���ƾ���.
//stage.h ���� �տ��ִ� ������Ͽ��� ���� ���� ���� �� ������ ȸ������ ��
class cStage
{
private:
	
	vector<cItem> m_ItemList;
	vector<cItem2> m_ItemList2;

	cCharacter*	m_pCharacter;
	cWeapon*	m_pWeapon;
	cWeapon2*	m_pWeapon2;

	Vector2f	m_Pos;

	PlayMp4		m_PlayMp4;

public : 
	cStage() ;
	 ~cStage();

	void	init();//�ʱ�ȭ
	void	Release();//�� ��
	void	Render();//�׸���
	void	FrameMove();//����ϱ�

//������ �ȵǰ� �ϰ� ������ �˷��� �ְ� ���� ��! �ؿ�ó�� Get,Set����~(��������,ĸ��ȭ)
/*	int GetHP()
	{
		return HP;
	}

	void SetHP(int t)
	{
		HP =t;
	}*/
};

#endif