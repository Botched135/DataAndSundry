#pragma once


int ExpBySqurare(int x, int y)
{
}

// Binary Search

// Levenshtein Distance 


// Binary Expression tree

// String to int
int StrToInt(const char* src)
{
    int result = 0, sign = 1;
    if (*src == '-')
    {
        sign = -1;
        src++;
    }

    while(*src != '\0')
    {
        result *= 10;
        result += *src - '0';
        src++;
    }
    return result * sign;
}


// String to float 
float StrToFloat(const char* src)
{
    float result = 0.0f, sign = 1.0;

    if(*src == '-')
    {
        sign = -1;
        src++;
    }

    // ??? 

    return result;
}
