#pragma once
class BinaryHeapNode;
class BinaryHeap
{
public:
    BinaryHeap(BinaryHeapNode*);
    ~BinaryHeap();
    void Insert(BinaryHeapNode*);
    void Remove(BinaryHeapNode*);
    void RemoveMax();
    void RemoveMin();
    BinaryHeapNode Find(int);
private:
    int m_size;
    BinaryHeapNode* m_root;
    void RecInsert(BinaryHeapNode*, BinaryHeapNode*);
    //set the next parent with free node here
};
class BinaryHeapNode
{
public:
    BinaryHeapNode(int);
    BinaryHeapNode* m_left, *m_right;
    int m_data;
};

BinaryHeap::BinaryHeap(BinaryHeapNode* root): m_root(root){}

void BinaryHeap::Insert(BinaryHeapNode* newNode)
{
    if (m_root == nullptr)
        m_root = newNode;
    else
        RecInsert(m_root, newNode);
        
}

void BinaryHeap::RecInsert(BinaryHeapNode* currentNode, BinaryHeapNode* newNode)
{
    if()
}