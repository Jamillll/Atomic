#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>
#include <fstream>

struct ShaderSource
{
    std::string vertexShader;
    std::string fragmentShader;
};

class Shader
{
private:
    unsigned int id;

public:
    Shader() { }

    Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
    {
        ShaderSource shaders = ParseShader(vertexShaderPath, fragmentShaderPath);
        id = CreateShader(shaders.vertexShader, shaders.fragmentShader);
        glUseProgram(id);
    }

    ~Shader() { glDeleteProgram(id); }

    void InitShader(std::string vertexShaderPath, std::string fragmentShaderPath)
    {
        ShaderSource shaders = ParseShader(vertexShaderPath, fragmentShaderPath);
        id = CreateShader(shaders.vertexShader, shaders.fragmentShader);
        glUseProgram(id);
    }

    int GetUniformLocation(const char* uniformName) { return glGetUniformLocation(GL_INT_IMAGE_1D, uniformName); }

private:
    ShaderSource ParseShader(const std::string vertexFilepath, const std::string fragmentFilepath)
    {
        ShaderSource source;
        std::ifstream stream;
        stream.open(vertexFilepath);

        std::string currentLine = "";
        while (getline(stream, currentLine))
        {
            source.vertexShader += currentLine + "\n";
        }

        stream.close();
        stream.open(fragmentFilepath);

        currentLine = "";
        while (getline(stream, currentLine))
        {
            source.fragmentShader += currentLine + "\n";
        }

        stream.close();

        return source;
    }

    unsigned int CompileShader(unsigned int type, const std::string& source)
    {
        unsigned int id = glCreateShader(type);
        const char* sourcePointer = source.c_str();
        glShaderSource(id, 1, &sourcePointer, NULL);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);

        if (result == GL_FALSE)
        {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

            char* message = (char*)alloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);

            std::cout << "FAILED TO COMPILE " << type << std::endl;
            std::cout << message << std::endl;

            glDeleteShader(id);
            return 0;
        }

        return id;
    }

    unsigned int CreateShader(const std::string& vertexShaderCode, const std::string& fragmentShaderCode)
    {
        unsigned int program = glCreateProgram();

        unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderCode);
        glAttachShader(program, vertexShader);

        unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderCode);
        glAttachShader(program, fragmentShader);

        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return program;
    }
};