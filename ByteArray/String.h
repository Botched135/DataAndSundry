#pragma once
#include <string.h>
#include <utility>
#include <ostream>
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
    //String& operator= (const String& other);
    String& operator= (String other);//assignment-operator

    friend std::ostream &operator<<(std::ostream &os, String const &str)
    {
        return os << str.m_str;
    }

    friend void swap(String& first, String& second) //no-throw swap function
    {
        using std::swap;

        swap(first.m_str, second.m_str);
    }
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

/*
//THIS IN A NAIVE IMPLEMENTATION
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
*/

String& String::operator= (String other)
{
    swap(*this, other);
    
    return *this;
}