#include <cstdio>

#ifndef NODE_HPP
#define NODE_HPP
class Node
{
private:
    Node *next = nullptr;
    int value = 0;

public:
    Node() : Node(0, nullptr) {}
    Node(int val) : Node(val, nullptr) {}
    Node(int val, Node *ptr) : value(val), next(ptr) {}
    Node *getNext(void) { return this->next; }
    int getValue(void) { return this->value; }
    void setNext(Node *ptr) { this->next = ptr; }
    void setValue(int val) { this->value = val; }
};
#endif // NODE_HPP

int main(void)
{
    Node *head = nullptr, *ptr = nullptr;
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    for (int loop = 1; loop <= n; loop++)
        if (head == nullptr)
        {
            head = new Node(loop);
            head->setNext(head);
            ptr = head;
        }
        else
        {
            ptr->setNext(new Node(loop, head));
            ptr = ptr->getNext();
        }
    Node *output = nullptr, *back = nullptr;
    while (ptr->getNext() != ptr)
    {
        for (int loop = 0; loop < k - 1; loop++)
            ptr = ptr->getNext();
        if (output == nullptr)
        {
            output = ptr->getNext();
            ptr->setNext(ptr->getNext()->getNext());
            output->setNext(nullptr);
            back = output;
        }
        else
        {
            back->setNext(ptr->getNext());
            ptr->setNext(ptr->getNext()->getNext());
            back = back->getNext();
            back->setNext(nullptr);
        }
    }
    if (back != nullptr)
    {
        back->setNext(ptr);
        back = back->getNext();
        back->setNext(nullptr);
    }
    else
    {
        output = ptr;
        output->setNext(nullptr);
    }
    Node *temp = nullptr;
    printf("<");
    while (output != nullptr)
    {
        temp = output;
        output = output->getNext();
        printf("%d", temp->getValue());
        if (output != nullptr)
            printf(", ");
        delete (temp);
    }
    printf(">\n");
    return 0;
}