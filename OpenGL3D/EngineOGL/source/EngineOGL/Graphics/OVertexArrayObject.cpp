#include <EngineOGL/Graphics/OVertexArrayObject.h>
#include <glad/glad.h>
OVertexArrayObject::OVertexArrayObject(const OVertexBufferData& data)
{

	glGenBuffers(1, &m_vertefBufferId);

	glGenVertexArrays(1, &m_vertexArrayObjectId);
	glBindVertexArray(m_vertexArrayObjectId);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertefBufferId);
	glBufferData(GL_ARRAY_BUFFER, data.vertexSize * data.listSize, data.verticesList, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, data.vertexSize, 0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	m_vertexBufferData = data;


}

OVertexArrayObject::~OVertexArrayObject()
{
	glDeleteBuffers(1, &m_vertefBufferId);
	glDeleteVertexArrays(1, &m_vertexArrayObjectId);

}

ui32 OVertexArrayObject::getId()
{
	return m_vertexArrayObjectId;
}

ui32 OVertexArrayObject::getVertexBufferSize()
{
	return m_vertexBufferData.listSize;
}

ui32 OVertexArrayObject::getVertexSize()
{
	return  m_vertexBufferData.vertexSize;
}
