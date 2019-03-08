#pragma once
class Double_Node;
class DoubleLinkedList
{
public:
    DoubleLinkedList(Double_Node*);
    ~DoubleLinkedList();
    void InsertNode(Double_Node*, Double_Node*);
private:
    DoubleLinkedList();
    Double_Node* m_head;
    Double_Node* m_tail;
};

DoubleLinkedList::DoubleLinkedList(Double_Node* rootNode)
{
    m_head = rootNode;
    m_tail = rootNode;

    rootNode->m_prev = nullptr;
    rootNode->m_next = nullptr;
}
void DoubleLinkedList::InsertNode(Double_Node* insertAfter, Double_Node* newNode)
{
    if (insertAfter == nullptr)
        return;
    
    if(insertAfter->m_next == nullptr)
        m_tail = newNode;
 
    newNode->m_next = insertAfter->m_next;
    newNode->m_next->m_prev = newNode;
    newNode->m_prev = insertAfter;
    insertAfter->m_next = newNode;

}

class Double_Node
{
public:
    Double_Node* m_prev, *m_next;
    int m_data;
};