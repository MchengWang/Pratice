#pragma once

#include <iostream>
#include <gl/glew.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if(!(x)) __debugbreak();
// 在宏函数中 使用 ‘\’ 作为换行符
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x , __FILE__ , __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
public:
	void Clear() const;
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};