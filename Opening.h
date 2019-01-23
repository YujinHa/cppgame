#ifndef OPENING_H__
#define OPENING_H__

class cOpening
{
private:
	Sprite		m_Sprite;
	PlayMp4		m_PlayMp4_Opening;
public:
	cOpening()
	{}
	~cOpening()
	{}

	void init()
	{
		PlaySound(L"Sound/openingbgm.wav",NULL,SND_ASYNC|SND_LOOP);
		m_PlayMp4_Opening.init("Video/opening_.mp4");
		m_PlayMp4_Opening.EndStop(true);
		m_Sprite.init("Image/skip.png");
	}

	void Release()
	{
		PlaySound(NULL,NULL,SND_ASYNC|SND_LOOP);
		m_PlayMp4_Opening.Release();
		m_Sprite.Release();
	}

	void Render()
	{
		m_PlayMp4_Opening.Render(10);
		m_Sprite.Render();
	}

	void FrameMove()
	{
		m_PlayMp4_Opening.m_size = Vector2f(g_Extern.WINDOWSIZE_WIDTH,g_Extern.WINDOWSIZE_HEIGHT);
		if(KeyDown(VK_SPACE))
		{
			g_Extern.g_nSceneNum=1;
		}
	}
};

#endif