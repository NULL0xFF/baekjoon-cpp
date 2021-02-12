#include <cstdio>
#include <cstring>

class Queue
{
private:
    class Node
    {
    private:
        Node *next = nullptr;
        int value = 0;

    public:
        Node() : Node(-1) {}
        Node(int i) : Node(i, nullptr) {}
        Node(int i, Node *ptr)
        {
            value = i;
            next = ptr;
        }
        Node *getNext() { return next; }
        int getValue() { return value; }
        void setNext(Node *ptr) { next = ptr; }
        void setValue(int i) { value = i; }
    };
    Node *frontPtr = nullptr, *endPtr = nullptr;

public:
    Queue() {}
    void push(const int i)
    {
        if (frontPtr == nullptr)
        {
            frontPtr = new Node(i);
            endPtr = frontPtr;
        }
        else
        {
            endPtr->setNext(new Node(i));
            endPtr = endPtr->getNext();
        }
    }
    int pop()
    {
        if (frontPtr == nullptr)
            return -1;
        int value = frontPtr->getValue();
        frontPtr = frontPtr->getNext();
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
    int back() { return empty() ? -1 : endPtr->getValue(); }
};

int main(void)
{
    Queue queue;
    int n = 0;
    scanf("%d", &n);
    {
        int valueInput = 0;
        char *commandInput = new char[6]();
        for (int loop = 0; loop < n; loop++)
        {
            scanf(" %s", commandInput);
            if (strcmp(commandInput, "push") == 0)
            {
                scanf("%d", &valueInput);
                queue.push(valueInput);
            }
            else if (strcmp(commandInput, "pop") == 0)
                printf("%d\n", queue.pop());
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