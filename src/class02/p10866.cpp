#include <cstdio>
#include <cstring>

class Deque
{
private:
    class Node
    {
    private:
        Node *prev = nullptr, *next = nullptr;
        int value = 0;

    public:
        Node() : Node(-1) {}
        Node(int i) : Node(i, nullptr) {}
        Node(int i, Node *prevPtr) : Node(i, prevPtr, nullptr) {}
        Node(int i, Node *prevPtr, Node *nextPtr)
        {
            value = i;
            prev = prevPtr;
            next = nextPtr;
        }
        Node *getPrev() { return prev; }
        Node *getNext() { return next; }
        int getValue() { return value; }
        void setPrev(Node *ptr) { prev = ptr; }
        void setNext(Node *ptr) { next = ptr; }
        void setValue(int i) { value = i; }
    };
    Node *frontPtr = nullptr, *backPtr = nullptr;

public:
    Deque() {}
    void push_front(const int i)
    {
        if (empty())
        {
            frontPtr = new Node(i);
            backPtr = frontPtr;
        }
        else
        {
            frontPtr->setPrev(new Node(i, nullptr, frontPtr));
            frontPtr = frontPtr->getPrev();
        }
    }
    void push_back(const int i)
    {
        if (empty())
        {
            frontPtr = new Node(i);
            backPtr = frontPtr;
        }
        else
        {
            backPtr->setNext(new Node(i, backPtr, nullptr));
            backPtr = backPtr->getNext();
        }
    }
    int pop_front()
    {
        if (empty())
            return -1;
        int value = frontPtr->getValue();
        Node *ptr = frontPtr;
        frontPtr = frontPtr->getNext();
        if (frontPtr == nullptr)
            backPtr = nullptr;
        else
            frontPtr->setPrev(nullptr);
        delete (ptr);
        return value;
    }
    int pop_back()
    {
        if (empty())
            return -1;
        int value = backPtr->getValue();
        Node *ptr = backPtr;
        backPtr = backPtr->getPrev();
        if (backPtr == nullptr)
            frontPtr = nullptr;
        else
            backPtr->setNext(nullptr);
        delete (ptr);
        return value;
    }
    int size()
    {
        if (empty())
            return 0;
        Node *ptr = frontPtr;
        int count = 0;
        while (ptr != nullptr)
        {
            count++;
            ptr = ptr->getNext();
        }
        return count;
    }
    bool empty() { return frontPtr == nullptr ? true : false; }
    int front() { return empty() ? -1 : frontPtr->getValue(); }
    int back() { return empty() ? -1 : backPtr->getValue(); }
};

int main(void)
{
    Deque queue;
    int n = 0;
    scanf("%d", &n);
    {
        int valueInput = 0;
        char *commandInput = new char[11]();
        for (int loop = 0; loop < n; loop++)
        {
            scanf(" %s", commandInput);
            if (strcmp(commandInput, "push_front") == 0)
            {
                scanf("%d", &valueInput);
                queue.push_front(valueInput);
            }
            else if (strcmp(commandInput, "push_back") == 0)
            {
                scanf("%d", &valueInput);
                queue.push_back(valueInput);
            }
            else if (strcmp(commandInput, "pop_front") == 0)
                printf("%d\n", queue.pop_front());
            else if (strcmp(commandInput, "pop_back") == 0)
                printf("%d\n", queue.pop_back());
            else if (strcmp(commandInput, "size") == 0)
                printf("%d\n", queue.size());
            else if (strcmp(commandInput, "empty") == 0)
                printf("%d\n", queue.empty() ? 1 : 0);
            else if (strcmp(commandInput, "front") == 0)
                printf("%d\n", queue.front());
            else if (strcmp(commandInput, "back") == 0)
                printf("%d\n", queue.back());
            else
                return 1;
        }
    }
    return 0;
}