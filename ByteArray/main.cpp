// ByteArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BitArray.h"
#include "Trie.h"
#include <vector>
#include "String.h"


int main()
{
    /*
    BitArray bitA(64);
    std::cout << bitA.GetIndex(63) << std::endl;;
    bitA.SetIndex(63, 1);
    std::cout << bitA.GetIndex(63) << std::endl;
    bitA.SetIndex(2, 1);
    bitA.SetIndex(33, 1);
    std::cout << 'b' - tolower('a');
    const char* str = "Hello";
    const char* str2 = str;
    while(*str != '\0')
    {
        std::cout << str <<" & " << str2 << std::endl;
        str++;
    }
    char c = 'c';
    c = c >> 2;
    std::cout << "++c: " << c << std::endl;
    */
    /*for (int i = 0; i < 1000; i++)
    {
    //Create some performance testing
        Trie testTrie;
        if ((i % 100) == 0)
            std::cout << "Hello" << std::endl;

        
    }*/
  /*  char** dictionary = nullptr;
    dictionary =  LoadDictFromFile("C:/Users/Bons/Desktop/New life Curricilum/DataStructures/ByteArray/ByteArray/dic.txt");
    Trie _trie(dictionary);

    std::cout << _trie.FindWord("hello") <<std::endl;
    std::cout << _trie.FindWord("HeLlo") << std::endl;
    std::cout << _trie.FindWord("equilibrium") << std::endl;
    delete dictionary;*/

    String s("Hello, World");
    String s1;
    std::cout << s << std::endl;
    s1 = "Hello World";
    std::cout << s1 << std::endl;;
    s1 = s;
    std::cout << s1;
    return 0;
}

