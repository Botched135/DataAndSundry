#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
class TrieNode;
class Trie
{
public:
    Trie();
    Trie(char **);
    ~Trie();
    int InsertWord(const char*);
    int InsertDictionary(char **);
    int FindWord(const char *);
    TrieNode* root;
};
class TrieNode
{
public:
    TrieNode()
    {
        value = nullptr;
        for(int i = 0; i < 28;i++)
            children[i] = nullptr;
    }
    TrieNode(const char* word)
    {
        strcpy(value, word);
        for (int i = 0; i < 28; i++)
            children[i] = nullptr;
    }
    ~TrieNode()
    {
        for (int i = 0; i < 28; i++)
        {
            if (children[i] != nullptr)
                delete children[i];
        }
    }
    char* value;
    TrieNode* children[28];
};


char** LoadDictFromFile(const char* path)
{
    std::ifstream file;
    int count = 0;
    char line[50];
    char ** dict;

    //Open file and check if good
    file.open(path);
    if(!file.good())
    {
        std::cout << "ERROR! File does not exist or is corrupted" << std::endl;
        return nullptr;
    }
    
    //Count words in file
    while(!file.eof())
    {
        file >> line;
        if (strlen(line) > 0)
            count++;
    }
    std::cout << count << " words in dictionary found" << std::endl;
    // Allocate sufficient large string array 
    dict = new char*[count];
    
    //Reset ifstream
    count = 0;
    file.clear();
    file.seekg(0, file.beg);
    
    // Copy words from file into the array
    while (!file.eof())
    {
       
        file >> line;
        if (strlen(line) > 0)
        {
            dict[count] = new char[50];
            strcpy(dict[count], line);
            count++;
        }
    }

    // Set the the index after the array to nullptr, which is used during insertion into the trie
    dict[count] = nullptr;
    

    file.close();
    std::cout << "Dictionary succesfully loaded(" << count<<" words)"<< std::endl;
    return dict;
}

Trie::Trie()
{
    root = new TrieNode();
}
Trie::Trie(char**  dict)
{
    root = new TrieNode();

    if (!InsertDictionary(dict))
        std::cout << "Insertion of dictionary failed" << std::endl;
}
Trie::~Trie()
{
    delete root;
}
int Trie::InsertDictionary(char** dict)
{
    // Iterate through the string array and insert the words into the trie 
    while(*dict != nullptr)
    {
        TrieNode* currentNode = root;
        const char* iterString = *dict;
        while (*iterString != '\0')
        {
            // Iterate through each letter of a word, and create a new node in the trie for new entries
            int charIndex = tolower(*iterString) - 'a';
            TrieNode* childNode = currentNode->children[charIndex];
            if (childNode == nullptr)
            {
                currentNode->children[charIndex] = new TrieNode();
                childNode = currentNode->children[charIndex];
            }

            currentNode = childNode;
            ++iterString;

        }
        // At the end of the iterating of the string, the node value is set to the string 
        if (currentNode->value == nullptr)
        {
            currentNode->value = new char[strlen(*dict) + 1];
            strcpy(currentNode->value, *dict);
        }
           

        ++dict;  
    }
    return 1;
}

int Trie::InsertWord(const char* str)
{
  
    if(FindWord(str))
    {
        std::cout << "The word \"" << str << "\" is already in the trie" << std::endl;
        return 0;
    }

    TrieNode* currentNode = root;
    const char* currentString = str;
    while (*currentString != '\0')
    {
        int charIndex = tolower(*currentString) - 'a';
        TrieNode* childNode = currentNode->children[charIndex];
        if (childNode == nullptr)
        {
            currentNode->children[charIndex] = new TrieNode();
            childNode = currentNode->children[charIndex];
        }

        currentNode = childNode;
        ++currentString;

    }
    if (currentNode->value == nullptr)
    {
        currentNode->value = new char[strlen(str) + 1];
        strcpy(currentNode->value, str);
        std::cout << "Successfully inserted \"" << str << "\" into the trie" << std::endl;
        return 1;
    }
    return 0;
}

int Trie::FindWord(const char* string)
{
    TrieNode* currentNode = root;
    const char* currentString = string;

    while (*currentString != '\0')
    {
        TrieNode* childNode = currentNode->children[tolower(*currentString) - 'a'];

        if (childNode == nullptr)
        {
            // Early out if there is a letter missing 
            std::cout << "The word \"" << string << "\" is not in the trie!" << std::endl;
            return 0;
        }

        currentNode = childNode;
        ++currentString;

    }

    // Use _stricmp to avoid being case-sensitive in comparison
    if (currentNode->value != nullptr)
        return _stricmp(currentNode->value, string) == 0;

    return 0;
}