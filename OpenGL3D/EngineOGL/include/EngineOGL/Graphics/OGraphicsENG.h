#pragma once
#include <EngineOGL/OPrerequisites.h>
#include<EngineOGL/Math/Ovec4.h>
#include <EngineOGL/Math/ORect.h>
class OGraphicsENG
{
public:
	OGraphicsENG();
	~OGraphicsENG();

public:
	void clear(const Ovec4& color);
	void setViewport(const ORect& size);
	OVertexArrayObjectPtr createVertexArrayObject(const OVertexBufferData& data);
	void setVertexArrayObject(const OVertexArrayObjectPtr& vao);
	void drawTriangles(ui32 vertexCount, ui32 offset);




};

