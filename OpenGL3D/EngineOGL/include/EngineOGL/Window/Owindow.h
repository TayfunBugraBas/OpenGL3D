#pragma once
#include <EngineOGL/Math/ORect.h>

class Owindow
{
public:
	Owindow();
	~Owindow();

	ORect getInnerSize();

	void makeCurrentContext();
	void present(bool vsync);

private:

	void* m_handle = nullptr;
	void* m_context = nullptr;




};

