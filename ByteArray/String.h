#pragma once
#include <string.h>
class String
{
public:
    String() 
    {
        m_str = new char[1];
        *m_str = 0;
    }
    ~String();
    String(const char* str);
    String(const String& other);//copy-constructor
    String& operator= (const String& other);//assignment-operator
private:
    char* m_str;
};

String::~String()
{
    delete[] m_str;
}

String::String(const char* str)
{
    m_str = new char[strlen(str)+1];
    strcpy(m_str, str);
}

String::String(const String& other)
{
    m_str = new char[strlen(other.m_str) + 1];
    strcpy(m_str, other.m_str);
}

String& String::operator= (const String& other)
{
    if(this != &other)
    {
        delete[] m_str;
        m_str = nullptr;

        const int length = strlen(other.m_str);

        m_str = new char[length + 1];
        strcpy(m_str, other.m_str);
    }
    return *this;
}