#pragma once
#include <iostream>
typedef unsigned int uint;
#define uint_bits (sizeof(uint)*CHAR_BIT) 
class BitArray
{
public:
    BitArray(uint);
    ~BitArray();
    bool &operator[] (uint);
    void SetIndex(uint, bool);
    bool GetIndex(uint);
private:
    uint m_size;
    uint* m_array;
};

BitArray::BitArray(uint size):m_size(size)
{
    uint elements = (m_size+uint_bits-1)/uint_bits;
    m_array = new uint[elements];
    for (int i = 0; i < elements; i++)
        m_array[i] = 0;
}
BitArray::~BitArray()
{
    delete[](m_array);
}


void BitArray::SetIndex(uint index, bool value)
{
    if (index >= m_size || index < 0)
    {
        std::cout << "Index out of bounds!" << std::endl;
        return;
    }
    uint bitmask = 1 << (index % uint_bits);

    m_array[index / uint_bits] = value ? m_array[index / uint_bits] | bitmask:
                                          m_array[index / uint_bits] & ~bitmask;   

}

bool BitArray::GetIndex(uint index)
{
    if (index >= m_size || index < 0)
    {
        std::cout << "Index out of bounds!" << std::endl;
        return 0;
    }
    uint bitmask = 1 << (index % uint_bits);

    return m_array[index / uint_bits] & bitmask;
}

bool& BitArray::operator[] (uint index)
{
    bool res;
    return res;
}