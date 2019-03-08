// ByteArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BitArray.h"

int main()
{
    BitArray bitA(64);
    std::cout << bitA.GetIndex(63) << std::endl;;
    bitA.SetIndex(63, 1);
    std::cout << bitA.GetIndex(63) << std::endl;
    bitA.SetIndex(2, 1);
    bitA.SetIndex(33, 1);
    return 0;
}

