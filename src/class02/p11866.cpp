#include <cstdio>

class Node
{
private:
    Node *next;
    int value;

public:
    Node() : Node(-1, nullptr) {}
    Node(int i) : Node(i, nullptr) {}
    Node(int i, Node *ptr)
    {
        value = i;
        next = ptr;
    }
    Node *getNext() { return this->next; }
    int getValue() { return this->value; }
    void setNext(Node *ptr) { this->next = ptr; }
    void setValue(int i) { this->value = i; }
};

int main(void)
{
    Node *start = nullptr, *end = nullptr;
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    for (int loop = 1; loop <= n; loop++)
    {
        if (start == nullptr)
        {
            start = new Node(loop);
            end = start;
        }
        else
        {
            end->setNext(new Node(loop));
            end = end->getNext();
        }
    }
    end->setNext(start);
    Node *ptr = end, *prev = nullptr;
    int *result = new int[n]();
    for (int loop = 0; loop < n; loop++)
    {
        for (int loopPtr = 0; loopPtr < k - 1; loopPtr++)
            ptr = ptr->getNext();
        prev = ptr;
        ptr = ptr->getNext();
        result[loop] = ptr->getValue();
        if (prev == ptr)
            break;
        prev->setNext(ptr->getNext());
    }
    printf("<");
    for (int loop = 0; loop < n; loop++)
        if (loop != n - 1)
            printf("%d, ", result[loop]);
        else
            printf("%d>", result[loop]);
    return 0;
}