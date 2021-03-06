#include <cstdio>

template <typename Type>
class Node
{
private:
    Node *next;
    Type value;

public:
    Node() : Node(nullptr, nullptr) {}
    Node(Type val) : Node(val, nullptr) {}
    Node(Type val, Node *ptr) : value(val), next(ptr) {}
    Node *getNext() { return this->next; }
    Type getValue() { return this->value; }
    void setNext(Node *ptr) { this->next = ptr; }
    void setValue(Type val) { this->value = val; }
};

int main(void)
{
    Node<unsigned int> *heap = nullptr;
    int n = 0;
    scanf("%d", &n);
    for (int loop = 0; loop < n; loop++)
    {
        unsigned int x = 0;
        scanf("%u", &x);
        if (x == 0)
        {
            if (heap != nullptr)
            {
                Node<unsigned int> *ptr = heap;
                heap = heap->getNext();
                printf("%u\n", ptr->getValue());
                delete (ptr);
            }
            else
                printf("0\n");
        }
        else if (heap == nullptr)
            heap = new Node<unsigned int>(x);
        else if (x <= heap->getValue())
            heap = new Node<unsigned int>(x, heap);
        else
        {
            Node<unsigned int> *ptr = heap;
            while (ptr->getNext() != nullptr)
            {
                if (x < ptr->getNext()->getValue())
                {
                    ptr->setNext(new Node<unsigned int>(x, ptr->getNext()));
                    break;
                }
                ptr = ptr->getNext();
            }
            if (ptr->getNext() == nullptr)
                ptr->setNext(new Node<unsigned int>(x));
        }
    }
    return 0;
}