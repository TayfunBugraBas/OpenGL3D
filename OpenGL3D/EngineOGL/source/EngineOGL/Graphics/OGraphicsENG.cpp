#include <EngineOGL/Graphics/OGraphicsENG.h>
#include <EngineOGL/Graphics/OVertexArrayObject.h>
#include <glad/glad.h>
#include <stdexcept>
#include <assert.h>



void OGraphicsENG::clear(const Ovec4& color)
{
	glClearColor(color.x, color.y, color.z, color.w);
	glClear(GL_COLOR_BUFFER_BIT);
}

void OGraphicsENG::setViewport(const ORect& size)
{

	glViewport(size.left, size.top, size.width, size.height);

}

OVertexArrayObjectPtr OGraphicsENG::createVertexArrayObject(const OVertexBufferData& data)
{
	return std::make_shared<OVertexArrayObject>(data);
}

void OGraphicsENG::setVertexArrayObject(const OVertexArrayObjectPtr& vao)
{
	glBindVertexArray(vao->getId());
}

void OGraphicsENG::drawTriangles(ui32 vertexCount, ui32 offset)
{
	glDrawArrays(GL_TRIANGLES,offset,vertexCount);

}
