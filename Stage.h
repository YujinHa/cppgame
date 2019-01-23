#ifndef STAGE_H__//class단점 자기들끼리 못찾음!so 이렇게 정의 내려줘야함! 히어로 클래스에서 STAGE_H__똑같이 쓰면 무시됨.
#define STAGE_H__//#ifndef와 #define 뒤에 이름은 같아야함.
//stage.h 보다 앞에있는 헤더파일에서 같은 내용 쓰면 그 내용이 회색으로 됨
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

	void	init();//초기화
	void	Release();//끌 때
	void	Render();//그리기
	void	FrameMove();//계산하기

//수정은 안되게 하고 싶지만 알려는 주고 싶을 때! 밑에처럼 Get,Set쓰기~(정보은닉,캡슐화)
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