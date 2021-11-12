#pragma once 
#include <iostream>
using namespace std;
template <class H>
class List
{
private:
    int size;
    struct NODE
    {
        H data;
        NODE* pNext;
        NODE* pPrev;
        NODE(H data)
        {
            this->data = data;
            this->pNext = this->pPrev = NULL;
        }
    };
    NODE* pHead;
    NODE* pTail;

public:
    List()
    {
        this->pHead = this->pTail = NULL;
        this->size = 0;
    }
    ~List()
    {
        for (int i = 0; i < this->size - 2; i++)
        {
            pHead = pHead->pNext;
            delete pHead->pPrev;
        }
        delete pHead;
    }
    NODE* contructorNode(H data)
    {
        NODE* node = new NODE(data);
        return node;
    }
    void push_back(H data)
    {
        NODE* node = contructorNode(data);
        if (pHead == NULL)
        {
            this->pHead = this->pTail = node;
            this->size++;
            return;
        }
        this->pTail->pNext = node;
        node->pPrev = this->pTail;
        this->pTail = node;
        this->size++;
    }
    void add(int index, H x)
    {
        NODE* node = new NODE(x);
        if (size == 0)
        {
            pHead = pTail = node;
        }
        else if (index == 0)
        {
            node->pNext = pHead;
            pHead->pPrev = node;
            pHead = node;
        }
        else if (index == size)
        {
            push_back(x);
        }
        else
        {
            NODE* temp = pHead;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->pNext;
            }
            node->pNext = temp->pNext;
            node->pPrev = temp;
            temp->pNext->pPrev = node;
            temp->pNext = node;
        }
        size++;
    }
    int Size()
    {
        return this->size;
    }
    H& operator[](int index)
    {
        NODE* node = this->pHead;
        for (int i = 0; i < index; i++)
        {
            node = node->pNext;
        }
        return node->data;
    }
    void erase(int index)
    {
        if (index < 0 || index >= this->size)
            return;
        else if (this->size == 0)
        {
            return;
        }
        else if (this->size == 1)
        {
            delete pHead;
            pHead = pTail = NULL;
        }
        else if (index == 0)
        {
            NODE* node = pHead->pNext;
            pHead->pNext->pPrev = NULL;
            delete pHead;
            pHead = node;
        }
        else if (index == this->size - 1)
        {
            NODE* node = pTail->pPrev;
            pTail->pPrev->pNext = NULL;
            delete pTail;
            pTail = node;
        }
        else
        {
            NODE* node = this->pHead;
            for (int i = 0; i < index; i++)
            {
                node = node->pNext;
            }
            node->pPrev->pNext = node->pNext;
            node->pNext->pPrev = node->pPrev;
            delete node;
        }
        this->size--;
    }
};
