#pragma once
#include <memory>
#include <EngineOGL/OPrerequisites.h>


class Owindow;
class OGraphicsENG;
class OGame
{
public:
	OGame();
	~OGame();

	virtual void onCreate();
	virtual void onUpdate();
	virtual void onQuit();


	void run();
	void quit();

protected:
	bool m_isRunning = true;
	std::unique_ptr<Owindow> m_display;
	std::unique_ptr<OGraphicsENG> m_graphicsEngine;

	OVertexArrayObjectPtr m_triangleVAO;

private:


};

