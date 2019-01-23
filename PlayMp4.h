#include <math.h>

struct PlayMp4
{

	Vector2f m_pos;
	Vector2f m_size;
	GLuint	m_Texid;
	VideoCapture cap1;
	Color4f		m_Color;

	int sizew;
	int sizeh;
	int Framecount;
	bool	bStop;
	void init(char *name)
	{
		bStop=false;
		cap1.open(name);
		m_pos =Vector2f(0,0);
		m_size = Vector2f(0,0);

		m_Texid = NULL;

		m_size = Vector2f(cap1.get(CAP_PROP_FRAME_WIDTH),cap1.get(CAP_PROP_FRAME_HEIGHT));
		sizew = m_size.x;
		sizeh = m_size.y;
		Framecount = cap1.get(CV_CAP_PROP_FRAME_COUNT);
		Mat  p;
		cap1>>p;

		glGenTextures(1, &m_Texid);
		glBindTexture(GL_TEXTURE_2D, m_Texid);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_size.x, m_size.y, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE,(GLvoid*)p.ptr());

		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		p.release();
		cap1.set(CV_CAP_PROP_POS_FRAMES,0);
		m_Color =Color4f(1,1,1,1);
	}

	void EndStop(bool p)
	{
		bStop =p;
	}
	void Release()
	{
		cap1.release();
	}


	void DrawBox(float size)
	{
		static GLfloat n[6][3] =
		{
			{-1.0, 0.0, 0.0},
			{0.0, 1.0, 0.0},
			{1.0, 0.0, 0.0},
			{0.0, -1.0, 0.0},
			{0.0, 0.0, 1.0},
			{0.0, 0.0, -1.0}
		};
		static GLint faces[6][4] =
		{
			{0, 1, 2, 3},
			{3, 2, 6, 7},
			{7, 6, 5, 4},
			{4, 5, 1, 0},
			{5, 6, 2, 1},
			{7, 4, 0, 3}
		};
		GLfloat v[8][3];


		v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
		v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
		v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
		v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
		v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
		v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

		for (int i = 0; i <6; i++) 
		{
			glBegin(GL_QUADS);
			glNormal3fv(&n[i][0]);
			glTexCoord2f(0,1);
			glVertex3fv(&v[faces[i][0]][0]);
			glTexCoord2f(0,0);
			glVertex3fv(&v[faces[i][1]][0]);
			glTexCoord2f(1,0);
			glVertex3fv(&v[faces[i][2]][0]);
			glTexCoord2f(1,1);
			glVertex3fv(&v[faces[i][3]][0]);
			glEnd();
		}
	}

	void Render(int dely)
	{
		int c = cap1.get(CV_CAP_PROP_POS_FRAMES);

		if(bStop==false)
		{
			if(c>=Framecount)
			{
				cap1.set(CV_CAP_PROP_POS_FRAMES,0);
			}
		}
		else
		{
			if(c>=Framecount)
				cap1.set(CV_CAP_PROP_POS_FRAMES,Framecount-1);
		}

		Mat  p;
		cap1>>p;
		glBindTexture(GL_TEXTURE_2D, m_Texid);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, sizew,sizeh, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE,(GLvoid*)p.ptr());
		p.release();

		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D,m_Texid);
		glColor4f(m_Color.r,m_Color.g,m_Color.b,m_Color.a);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glTranslatef((m_size.x/2)+m_pos.x,g_Extern.WINDOWSIZE_HEIGHT-m_pos.y-(m_size.y/2),0);

		glScalef(-m_size.x,-m_size.y,1);
		//glRotatef(t,1,1,1);
		DrawBox(1);
		glBindTexture(GL_TEXTURE_2D,0);
		glPopMatrix();
		Sleep(dely);
	}
};