#include <cstdio>

class BigInt
{
private:
    class Node
    {
    private:
        Node *nextNode;
        int value;

    public:
        Node() : Node(0) {}
        Node(int val) : Node(val, nullptr) {}
        Node(int val, Node *ptr)
        {
            this->value = val;
            this->nextNode = ptr;
        }
        int getValue() { return this->value; }
        Node *getNextNode() { return this->nextNode; }
        void setValue(int val) { this->value = val; }
        void setNextNode(Node *ptr) { this->nextNode = ptr; }
    };
    Node *front = nullptr, *end = nullptr;

public:
    BigInt() : BigInt(0) {}
    BigInt(int val) : BigInt((long)val) {}
    BigInt(long val) : BigInt((long long)val) {}
    BigInt(long long val)
    {
        while (val != 0)
        {
            if (this->front == nullptr)
            {
                this->front = new Node(val % 10);
                this->end = this->front;
            }
            else
            {
                this->end->setNextNode(new Node(val % 10));
                this->end = this->end->getNextNode();
            }
            val = val / 10;
        }
        if(this->front == nullptr)
        {
            this->front = new Node(0);
            this->end = this->front;
        }
    }
    char *toString()
    {
        char *result = nullptr;
        int length = 0;
        {
            Node *ptr = this->front;
            while (ptr != nullptr)
            {
                ptr = ptr->getNextNode();
                length++;
            }
        }
        {
            Node *ptr = this->front;
            result = new char[length + 1]();
            for (int loop = length; loop > 0; loop--)
            {
                result[loop - 1] = ptr->getValue() + '0';
                ptr = ptr->getNextNode();
            }
        }
        return result;
    }
};

int main(void)
{
    BigInt a(0), b(12345678912341563418656789);
    printf("a: %s\nb: %s\n", a.toString(), b.toString());
    return 0;
}