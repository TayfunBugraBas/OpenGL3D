#include <EngineOGL/Game/OGame.h>
#include <EngineOGL/Window/Owindow.h>
#include<Windows.h>

OGame::OGame()
{
	m_display = std::unique_ptr<Owindow>( new Owindow());
}

OGame::~OGame()
{
	
}

void OGame::run()
{
	MSG msg;
	while (m_isRunning && !m_display->isClosed()) {

		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
		Sleep(1);


	}
}

void OGame::quit()
{
	m_isRunning = false;
}
