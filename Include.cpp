#include<stdlib.h>
#include"glut.h"
#pragma comment(lib,"glut32.lib") 

#include <math.h>
#include <stdio.h>
#include <Windows.h>

int WINDOWSIZE_WIDTH =1024 ;
int WINDOWSIZE_HEIGHT =768 ;


#include "vector.h"

#include "Texture.h"
#include "Sprite.h"


#define PI 3.14

inline int KeyDown( int vk )
{

	return ((GetAsyncKeyState(vk) & 0x8000 ) ? 1 : 0 ) ;

}

inline int KeyUp( int vk )
{

	return ((GetAsyncKeyState(vk) & 0x8000 ) ? 0 : 1 ) ;

}