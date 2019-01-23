//외부라이브러리 이용시 추천 경로
#include<stdlib.h>
#include"glut.h"//<>와""의 차이점:<>는 윈도우 내에 접근할 때 또는 정해놓은 패치로 접근할 때 사용,""는 프로잭트 내의 폴더로 들어갈 때 사용
#pragma comment(lib,"glut32.lib") 

#include <math.h>
#include <stdio.h>
#include <Windows.h>
#pragma comment(lib,"winmm.lib")
#include <vector>
using namespace std;

#include "OpenCV\InitOpenCV.h" // 유용하게 동영상 첨부 가능하게 함
#include "vector.h"

struct ExternStruct//전역변수 모아놓음
{
	int WINDOWSIZE_WIDTH ;
	int WINDOWSIZE_HEIGHT;
	
	Vector2f	g_Mouse;//마우스 눌렀다 땠을 때 이 값 갱신
	int		g_nSceneNum;

	int cRan1;
	int cRan2;
	int wRan1;
	int wRan2;
	int iRan1;
	int iRan2;
	int Win;
	int Lose;

};
extern ExternStruct g_Extern;


#include "Texture.h"
#include "Sprite.h"

#include "PlayMp4.h"

#define PI 3.14

static int KeyDown( int vk )//키보드 다운 됐을 때 이벤트 int vk는 아스키코드 사용
{

	return ((GetAsyncKeyState(vk) & 0x8000 ) ? 1 : 0 ) ;

}

static int KeyUp( int vk )
{

	return ((GetAsyncKeyState(vk) & 0x8000 ) ? 0 : 1 ) ;

}


#include "Weapon.h"
#include "Weapon2.h"
#include "Hp.h"
#include "Hp2.h"
#include "Character.h"
#include "Item.h"
#include "Item2.h"
#include "Stage.h"//히어로가 stage위에 있어야 함(히어로가 stage에 포함될 경우)
#include "Select.h"
#include "Opening.h"
#include "Ending.h"