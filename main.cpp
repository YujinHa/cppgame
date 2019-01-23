#include "Include.h"
#include<time.h>//
ExternStruct g_Extern;

cStage*		m_Stage =NULL;
cSelect*		m_Select =NULL;
cEnding*		m_Ending =NULL;
cOpening*		m_OPening =NULL;

Sprite			m_Paid;
float			m_fPaidtime;
bool			m_bPaid;

int g_nBeforSceneNum=0;
////////////////////////////////////////////////////////////


void init()//초기화,동적할당
{
	m_bPaid =false;
	m_Paid.init();
	m_Paid.m_Color =Color4f(0,0,0,0);

	g_Extern.g_Mouse =Vector2f(-1,-1);

	/*if(m_Stage==NULL)
	{
	m_Stage = new cStage();
	m_Stage->init();
	}*/

	m_OPening= new cOpening();
	m_OPening->init();

}

void FrameMove()
{

	if(g_Extern.g_nSceneNum!=g_nBeforSceneNum)
	{
		m_bPaid=true;

	}
	if(m_bPaid==true)
	{
		m_fPaidtime+=10;

		if(m_fPaidtime>=180)
		{
			m_bPaid=false;
			m_fPaidtime=0;
		}

		if(m_fPaidtime==90)
		{
			switch(g_nBeforSceneNum)
			{
			case 0:
				m_OPening->Release();
				delete m_OPening;
				m_OPening=NULL;
				break;
			case 1:
				m_Select->Release();
				delete m_Select;
				m_Select=NULL;
				break;
			case 2:
				m_Stage->Release();
				delete m_Stage;
				m_Stage=NULL;
				break;
			case 3:
				m_Ending->Release();
				delete m_Ending;
				m_Ending=NULL;
				break;
			}

			switch(g_Extern.g_nSceneNum)
			{
			case 0:
				m_OPening= new cOpening();
				m_OPening->init();
				break;
			case 1:
				m_Select= new cSelect();
				m_Select->init();
				break;
			case 2:
				m_Stage= new cStage();
				m_Stage->init();
				break;
			case 3:
				m_Ending= new cEnding();
				m_Ending->init();
				break;
			}


			g_nBeforSceneNum=g_Extern.g_nSceneNum;
		}

	}
	if(m_bPaid==false||m_fPaidtime>=100)
	{
		switch(g_Extern.g_nSceneNum)
		{
		case 0:
			if(m_OPening!=NULL)
				m_OPening->FrameMove();
			break;
		case 1:
			if(m_Select!=NULL)
				m_Select->FrameMove();
			break;
		case 2:
			if(m_Stage!=NULL)
				m_Stage->FrameMove();
			break;
		case 3:
			if(m_Ending!=NULL)
				m_Ending->FrameMove();
			break;
		}
	}

	m_Paid.m_Color =Color4f(0,0,0,sin(m_fPaidtime/180.0f*3.14));
	m_Paid.m_size =Vector2f(g_Extern.WINDOWSIZE_WIDTH,g_Extern.WINDOWSIZE_HEIGHT);


}

void Render()//그리기
{
	switch(g_Extern.g_nSceneNum)
	{
	case 0:
		if(m_OPening!=NULL)
			m_OPening->Render();
		break;
	case 1:
		if(m_Select!=NULL)
			m_Select->Render();
		break;
	case 2:
		if(m_Stage!=NULL)
			m_Stage->Render();
		break;
	case 3:
		if(m_Ending!=NULL)
			m_Ending->Render();
		break;
	}
}

void Release()
{
	if(m_Stage!=NULL)
	{
		m_Stage->Release();
		delete m_Stage;
		m_Stage=NULL;
	}

	if(m_Select!=NULL)
	{
		m_Select->Release();
		delete m_Select;
		m_Select=NULL;
	}

	if(m_Ending!=NULL)
	{
		m_Ending->Release();
		delete m_Ending;
		m_Ending=NULL;
	}
	if(m_OPening!=NULL)
	{
		m_OPening->Release();
		delete m_OPening;
		m_OPening=NULL;
	}

	m_Paid.Release();
}

/////////////////////////////////////////////////////////////

void display()
{ 
	FrameMove();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//이미지 겹쳤을 때 어떤 걸 잘 보이게 할건지 결정

	glViewport(0,0,g_Extern.WINDOWSIZE_WIDTH,g_Extern.WINDOWSIZE_HEIGHT);

	glMatrixMode(GL_PROJECTION);//z값 이용 원근투영(멀수록 작게),직교투영(멀리있던 앞에 있던 크기 같게)
	glLoadIdentity();
	glOrtho(0,g_Extern.WINDOWSIZE_WIDTH,0,g_Extern.WINDOWSIZE_HEIGHT,0.01,1000);


	glEnable(GL_BLEND);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5, 0.5, 0.5, 1.0);
	Render();
	m_Paid.Render();
	glutSwapBuffers(); 

}


void onIdle()
{
	g_Extern.WINDOWSIZE_WIDTH= glutGet(GLUT_WINDOW_WIDTH);
	g_Extern.WINDOWSIZE_HEIGHT= glutGet(GLUT_WINDOW_HEIGHT);

	display();
	Sleep(1000.0f/60.0f); 
}


void onMouse(int btn ,int state, int x,int y)
{

	if(btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		g_Extern.g_Mouse.x=x;
		g_Extern.g_Mouse.y=y;

	}

}



int main()
{
	g_Extern.g_nSceneNum=0;
	srand(time(NULL));
	g_Extern.WINDOWSIZE_WIDTH=1300;
	g_Extern.WINDOWSIZE_HEIGHT=900;

	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); 
	glutInitWindowSize(g_Extern.WINDOWSIZE_WIDTH, g_Extern.WINDOWSIZE_HEIGHT);
	glutCreateWindow("SEN'S MISSING(부제:행방불명된 센의 행적)");

	glEnable(GL_TEXTURE_2D);
	init();
	glutDisplayFunc(display); 
	atexit(Release);
	glutMouseFunc(onMouse); 
	glutIdleFunc(onIdle);
	glutMainLoop(); 

	return 0;

} 
