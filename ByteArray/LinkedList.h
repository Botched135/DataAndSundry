#pragma once
#include <iostream>
class SingleNode;
class LinkedList
{
public:
    void Insert(SingleNode*, SingleNode*);
    void Remove(SingleNode*);
    SingleNode* Find(int);
private:
    SingleNode* RecFind(int, SingleNode*);
    void RecRemove(SingleNode*, SingleNode*);
    SingleNode* m_head;
    SingleNode* m_tail;
};

class SingleNode
{
public:
    SingleNode* m_next;
    int m_data;
};

void LinkedList::Insert(SingleNode* prevNode, SingleNode* newNode)
{
    if(prevNode == nullptr)
    {
        if(m_head ==nullptr)
        {
            m_head = newNode;
            m_tail = newNode;
            newNode->m_next = nullptr;
        }
        else
        {
            m_head->m_next = newNode;
            m_tail = newNode;
            newNode->m_next = nullptr;
        }
           

    }
    else
    {
        newNode->m_next = prevNode->m_next;
        prevNode->m_next = newNode;
        if (prevNode == m_tail)
            m_tail = newNode;
    }
}

void LinkedList::Remove(SingleNode* node)
{
    if(m_head == node)
    {
        m_head = node->m_next;
        return;
    }
    RecRemove(m_head, node);
}
void RecRemove(SingleNode* currentNode, SingleNode* nodeToRemove)
{
    SingleNode* nextNode = currentNode->m_next;
    if(nextNode == nodeToRemove)
    {
        nextNode = nodeToRemove->m_next;
        return;
    }
    RecRemove(nextNode, nodeToRemove);
}

SingleNode* LinkedList::Find(int data)
{
    return RecFind(data,m_head);
}

SingleNode* LinkedList::RecFind(int data, SingleNode* currentNode)
{
    if (currentNode->m_data == data)
        return currentNode;
    return RecFind(data, currentNode->m_next);
}