#include "Shader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"

Shader::Shader(const std::string& filepath)
	:m_FilePath(filepath) , m_RendererID(0)
{
	ShaderProgramSource source = ParseShader(filepath);
	m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(m_RendererID));
}

ShaderProgramSource Shader::ParseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX; // 将着色器设置为顶点着色器
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT; // 将着色器设置为片段着色器
		}
		else
		{
			ss[(int)type] << line << "\n";
		}
	}

	return { ss[0].str() , ss[1].str() };
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
	// 创建着色器对象
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	// 替换着色器对象中的源代码
	glShaderSource(id, 1, &src, nullptr);
	// 编译着色器对象
	glCompileShader(id);

	// 错误处理
	int result;
	// 从着色器对象返回一个参数
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		// 从着色器对象返回一个参数
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(length * sizeof(char));
		// 返回着色器对象的信息日志
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "编译失败" << (type == GL_VERTEX_SHADER ? "顶点" : "片段") << "着色器！" << std::endl;
		std::cout << message << std::endl;

		// 删除着色器对象
		glDeleteShader(id);

	}

	return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShaper)
{
	// 创建程序对象
	GLCall(unsigned int program = glCreateProgram());
	// 构造顶点着色器
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	// 构造片段着色器
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShaper);

	// 将着色器对象附加到程序对象
	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));
	// 链接程序对象
	GLCall(glLinkProgram(program));
	// 验证程序对象
	GLCall(glValidateProgram(program));

	// 删除着色器对象
	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));

	return program;
}

void Shader::Bind() const
{
	GLCall(glUseProgram(m_RendererID));
}

void Shader::Unbind() const
{
	GLCall(glUseProgram(0));
}

void Shader::SetUniform1i(const std::string& name, int value)
{
	GLint location = GetUniformLocation(name);
	GLCall(glUniform1f(location , value));
}

void Shader::SetUniform1f(const std::string& name, float value)
{
	GLint location = GetUniformLocation(name);
	GLCall(glUniform1f(location, value));
}

void Shader::SetUniform2f(const std::string& name, const glm::vec2& value)
{
	GLint location = GetUniformLocation(name);
	GLCall(glUniform2f(location, value.x, value.y));
}

void Shader::SetUniform3f(const std::string& name, const glm::vec3& value)
{
	GLint location = GetUniformLocation(name);
	GLCall(glUniform3f(location, value.x, value.y, value.z));
}

void Shader::SetUniform4f(const std::string& name, const glm::vec4& value)
{
	GLint location = GetUniformLocation(name);
	GLCall(glUniform4f(location, value.x, value.y, value.z, value.w));
}

void Shader::SetUniformMat3(const std::string& name, const glm::mat3& matrix)
{
	GLint location = GetUniformLocation(name);
	GLCall(glUniformMatrix3fv(location, 1, GL_FALSE, &matrix[0][0]));
}

void Shader::SetUniformMat4(const std::string& name, const glm::mat4& matrix)
{
	GLint location = GetUniformLocation(name);
	GLCall(glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]));
}

int Shader::GetUniformLocation(const std::string& name) const
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];

	GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
	if (location == -1)
		std::cout << "警告：统一变量 ‘" << name << "’ 不存在！" << std::endl;

	m_UniformLocationCache[name] = location;
	return location;
}