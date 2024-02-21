#include "Queue.h"


template<class T>
Queue<T>::Queue(int max)
{
    head = tail = nullptr;
    length = 0;
}

template<class T>
Queue<T>::Queue()
{
    head = tail = nullptr;
    length = 0;
}

template<class T>
Queue<T>::~Queue()
{
    MakeEmpty();
}

template<class T>
void Queue<T>::MakeEmpty()
{
    while(head != nullptr)
    {
        Node* tmp = head;
        head = head->next;
        if(head == nullptr)
            tail = nullptr;
        delete tmp;
        length--;
    }
}

template<class T>
bool Queue<T>::IsEmpty() const
{
    return head == nullptr;
}

template<class T>
bool Queue<T>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return false;
}

template<class T>
void Queue<T>::Enqueue(T newItem)
{
    Node* newNode = new Node;
    newNode->value = newItem;

    if(head == nullptr)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }

    length++;
}

template<class T>
T Queue<T>::Dequeue()
{
    if(head == nullptr)
        throw EmptyQueue();

    Node* tmp = head;
    head = head->next;
    if(head == nullptr)
        tail = nullptr;
    delete tmp;
    length--;
}
