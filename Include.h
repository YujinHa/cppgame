//�ܺζ��̺귯�� �̿�� ��õ ���
#include<stdlib.h>
#include"glut.h"//<>��""�� ������:<>�� ������ ���� ������ �� �Ǵ� ���س��� ��ġ�� ������ �� ���,""�� ������Ʈ ���� ������ �� �� ���
#pragma comment(lib,"glut32.lib") 

#include <math.h>
#include <stdio.h>
#include <Windows.h>
#pragma comment(lib,"winmm.lib")
#include <vector>
using namespace std;

#include "OpenCV\InitOpenCV.h" // �����ϰ� ������ ÷�� �����ϰ� ��
#include "vector.h"

struct ExternStruct//�������� ��Ƴ���
{
	int WINDOWSIZE_WIDTH ;
	int WINDOWSIZE_HEIGHT;
	
	Vector2f	g_Mouse;//���콺 ������ ���� �� �� �� ����
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

static int KeyDown( int vk )//Ű���� �ٿ� ���� �� �̺�Ʈ int vk�� �ƽ�Ű�ڵ� ���
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
#include "Stage.h"//����ΰ� stage���� �־�� ��(����ΰ� stage�� ���Ե� ���)
#include "Select.h"
#include "Opening.h"
#include "Ending.h"