#ifndef ENDING_H__
#define ENDING_H__

class cEnding
{
private:
	PlayMp4		m_PlayMp4_Ending;
	Sprite		m_Sprite;

public:
	cEnding()
	{}
	~cEnding()
	{}

	void init()
	{
//		PlaySound(L"Sound/end.wav",NULL,SND_ASYNC|SND_LOOP);

		if((g_Extern.Win == 0) && (g_Extern.Lose ==1))
		{
			PlaySound(L"Sound/1w2l.wav",NULL,SND_ASYNC|SND_LOOP);
			m_Sprite.init("Image/1w2l.png");
			m_Sprite.m_pos=Vector2f(300,230);
			m_PlayMp4_Ending.init("Video/1w2l (2).mp4");
		}
		if((g_Extern.Win == 0) && (g_Extern.Lose == 2))
		{
			PlaySound(L"Sound/1w3l.wav",NULL,SND_ASYNC|SND_LOOP);
			m_Sprite.init("Image/1w3l_2.png");
			m_Sprite.m_pos=Vector2f(300,230);
			m_PlayMp4_Ending.init("Video/1w3l (2).mp4");
		}
		if((g_Extern.Win == 1) && (g_Extern.Lose ==0))
		{
			PlaySound(L"Sound/2w1l.wav",NULL,SND_ASYNC|SND_LOOP);
			m_Sprite.init("Image/2w1l_2.png");
			m_Sprite.m_pos=Vector2f(300,230);
			m_PlayMp4_Ending.init("Video/2w1l (2).mp4");
		}
		if((g_Extern.Win == 1) && (g_Extern.Lose == 2))
		{
			PlaySound(L"Sound/2w3l.wav",NULL,SND_ASYNC|SND_LOOP);
			m_Sprite.init("Image/2w3l_2.png");
			m_Sprite.m_pos=Vector2f(300,230);
			m_PlayMp4_Ending.init("Video/2w3l (2).mp4");
		}
		if((g_Extern.Win == 2) && (g_Extern.Lose == 0))
		{
			PlaySound(L"Sound/u.wav",NULL,SND_ASYNC|SND_LOOP);
			m_Sprite.init("Image/3w1l.png");
			m_Sprite.m_pos=Vector2f(300,230);
			m_PlayMp4_Ending.init("Video/3w1l (2).mp4");
		}
		if((g_Extern.Win == 2) && (g_Extern.Lose == 1))
		{
			PlaySound(L"Sound/ub.wav",NULL,SND_ASYNC|SND_LOOP);
			m_Sprite.init("Image/3w2l_2.png");
			m_Sprite.m_pos=Vector2f(300,230);
			m_PlayMp4_Ending.init("Video/3w2l (2).mp4");
		}

		if((g_Extern.Win == 0) && (g_Extern.Lose == 0))
		{
			m_PlayMp4_Ending.init("Video/1w3l (2).mp4");
		}
		if((g_Extern.Win == 1) && (g_Extern.Lose == 1))
		{
			m_PlayMp4_Ending.init("Video/Haku.mp4");
		}
		if((g_Extern.Win == 2) && (g_Extern.Lose == 2))
		{
			PlaySound(L"Sound/ub.wav",NULL,SND_ASYNC|SND_LOOP);
			m_PlayMp4_Ending.init("Video/3w2l (2).mp4");
		}
	}

	void Release()
	{
		PlaySound(NULL,NULL,SND_ASYNC|SND_LOOP);
		m_PlayMp4_Ending.Release();
		m_Sprite.Release();
	}

	void Render()
	{
		m_PlayMp4_Ending.Render(10);
		m_Sprite.Render();
	}

	void FrameMove()
	{
		m_PlayMp4_Ending.m_size = Vector2f(g_Extern.WINDOWSIZE_WIDTH,g_Extern.WINDOWSIZE_HEIGHT);
		if(KeyDown(VK_SPACE))
		{
			g_Extern.g_nSceneNum=0;
		}
	}
};

#endif