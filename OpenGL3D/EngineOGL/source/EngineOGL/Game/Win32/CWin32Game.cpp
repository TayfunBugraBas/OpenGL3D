#include <EngineOGL/Game/OGame.h>
#include <EngineOGL/Window/Owindow.h>
#include <EngineOGL/Graphics/OGraphicsENG.h>
#include<Windows.h>




void OGame::run()
{
	onCreate();
	while (m_isRunning) {
		MSG msg = {};

		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				m_isRunning = false;
				continue;
			}
			else {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}


		}
		onUpdate();


	}
	onQuit();
}
