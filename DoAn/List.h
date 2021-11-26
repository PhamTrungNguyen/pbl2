#pragma once
#include <iostream>
using namespace std;
template <class T>
class List
{
private:
    int _size;
    struct NODE
    {
        T data;
        NODE* pNext;
        NODE* pPrev;
        NODE(T data)
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
        this->_size = 0;
    }
    ~List()
    {
        for (int i = 0; i < this->_size - 2; i++)
        {
            pHead = pHead->pNext;
            delete pHead->pPrev;
        }
        delete pHead;
    }
    NODE* contructorNode(T data)
    {
        NODE* node = new NODE(data);
        return node;
    }
    void push_back(T data)
    {
        NODE* node = contructorNode(data);
        if (pHead == NULL)
        {
            this->pHead = this->pTail = node;
            this->_size++;
            return;
        }
        this->pTail->pNext = node;
        node->pPrev = this->pTail;
        this->pTail = node;
        this->_size++;
    }
    int Size()
    {
        return this->_size;
    }
    T& operator[](int index)
    {
        NODE* node = this->pHead;
        for (int i = 0; i < index; i++)
        {
            node = node->pNext;
        }
        return node->data;
    }
    void add(int index, T x)
    {
        NODE* node = new NODE(x);
        if (_size == 0)
        {
            pHead = pTail = node;
        }
        else if (index == 0)
        {
            node->pNext = pHead;
            pHead->pPrev = node;
            pHead = node;
        }
        else if (index == _size)
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
        _size++;
    }
    void erase(int index)
    {
        if (index < 0 || index >= this->_size)
            return;
        else if (this->_size == 0)
        {
            return;
        }
        else if (this->_size == 1)
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
        else if (index == this->_size - 1)
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
        this->_size--;
    }
    void clear()
    {
        if (_size == 0)
            return;
        if (_size == 1)
        {
            delete pHead;
            pHead = pTail = NULL;
            _size = 0;
            return;
        }
        NODE* tempPrev = pHead;
        NODE* tempNext = pHead->pNext;
        for (int i = 0; i < _size - 1; i++)
        {
            delete tempPrev;
            tempPrev = tempNext;
            tempNext = tempNext->pNext;
        }
        delete tempPrev;
        _size = 0;
    }
    void erase(int begin, int end)
    {
        for (int i = begin; i <= end; i++)
            erase(begin);
    }
};