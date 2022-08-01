#include <EngineOGL/Game/OGame.h>
#include <EngineOGL/Window/Owindow.h>
#include <EngineOGL/Graphics/OGraphicsENG.h>
#include <EngineOGL/Graphics/OVertexArrayObject.h>


OGame::OGame()
{
	m_graphicsEngine = std::make_unique<OGraphicsENG>();	
	m_display = std::make_unique<Owindow>();

	m_display->makeCurrentContext();

	m_graphicsEngine->setViewport(m_display->getInnerSize());

}

OGame::~OGame()
{
	
}

void OGame::onCreate()
{
	const f32 triagnleVertices[] = {
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.0f,0.5f,0.0f
	};

	m_triangleVAO = m_graphicsEngine->createVertexArrayObject({(void*)triagnleVertices,sizeof(f32)*3,3});

	
}

void OGame::onUpdate()
{
	m_graphicsEngine->clear(Ovec4(1, 0, 0, 1));

	m_graphicsEngine->setVertexArrayObject(m_triangleVAO);
	m_graphicsEngine->drawTriangles(m_triangleVAO->getVertexBufferSize(), 0);

	m_display->present(false);
}

void OGame::onQuit()
{
}


void OGame::quit()
{
	m_isRunning = false;
}
