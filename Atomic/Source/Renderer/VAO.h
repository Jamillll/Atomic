#pragma once

class VAO
{
private:
	unsigned int m_id;

public:
	unsigned int m_count;

	VAO();
	~VAO();
	
	void SetData(void* data, int size);
	void Bind();
};