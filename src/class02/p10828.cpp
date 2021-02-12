#include <cstdio>
#include <cstring>

class Stack
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
    Node *front = nullptr, *end = nullptr;

public:
    Stack() {}
    void push(const int i)
    {
        if (front == nullptr)
        {
            front = new Node(i);
            end = front;
        }
        else
        {
            Node *ptr = new Node(i, front);
            front = ptr;
        }
    }
    int pop()
    {
        if (front == nullptr)
            return -1;
        int value = front->getValue();
        front = front->getNext();
        return value;
    }
    int size()
    {
        Node *ptr = front;
        int count = 0;
        while (ptr != nullptr)
        {
            count++;
            ptr = ptr->getNext();
        }
        return count;
    }
    bool empty()
    {
        return size() == 0;
    }
    int top()
    {
        if (front == nullptr)
            return -1;
        return front->getValue();
    }
};

int main(void)
{
    Stack stack;
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
                stack.push(valueInput);
            }
            else if (strcmp(commandInput, "pop") == 0)
                printf("%d\n", stack.pop());
            else if (strcmp(commandInput, "size") == 0)
                printf("%d\n", stack.size());
            else if (strcmp(commandInput, "empty") == 0)
                printf("%d\n", stack.empty() ? 1 : 0);
            else if (strcmp(commandInput, "top") == 0)
                printf("%d\n", stack.top());
            else
                return 1;
        }
    }
    return 0;
}