#include <cstdio>
#include <cmath>
#include <cstring>

class BigInt
{
private:
    class Node
    {
    private:
        Node *nextNode;
        int value;

    public:
        Node() : Node(0, nullptr) {}
        Node(int val) : Node(val, nullptr) {}
        Node(int val, Node *ptr)
        {
            this->value = val;
            this->nextNode = ptr;
        }
        Node *getNextNode() { return this->nextNode; }
        int getValue() { return this->value; }
        void setNextNode(Node *ptr) { this->nextNode = ptr; }
        void setValue(int val) { this->value = val; }
    };
    Node *front = nullptr, *end = nullptr;
    BigInt(Node *fPtr, Node *ePtr)
    {
        this->front = fPtr;
        this->end = ePtr;
    }

public:
    BigInt(int val)
    {
        this->front = new Node(val % 10);
        this->end = this->front;
        val = val / 10;
        while (val != 0)
        {
            this->end->setNextNode(new Node(val % 10));
            this->end = this->end->getNextNode();
            val = val / 10;
        }
    }
    BigInt add(const BigInt b)
    {
        Node *aPtr = this->front, *bPtr = b.front, *cPtr = new Node(0);
        Node *cPtrFront = cPtr, *cPtrPrev = nullptr;
        {
            bool comp = false;
            while (true)
            {
                // Escape
                if (aPtr == nullptr && bPtr == nullptr)
                    break;
                if (cPtrPrev == cPtr)
                {
                    cPtr->setNextNode(new Node(0));
                    cPtr = cPtr->getNextNode();
                }
                if (aPtr == nullptr)
                {
                    cPtr->setValue(cPtr->getValue() + bPtr->getValue());
                    if (cPtr->getValue() / 10 > 0)
                    {
                        cPtr->setValue(cPtr->getValue() % 10);
                        comp = true;
                    }
                    bPtr = bPtr->getNextNode();
                    // if (cPtr->getNextNode() == nullptr)
                    //     cPtr->setNextNode(new Node(0));
                    // cPtr = cPtr->getNextNode();
                }
                else if (bPtr == nullptr)
                {
                    cPtr->setValue(cPtr->getValue() + aPtr->getValue());
                    if (cPtr->getValue() / 10 > 0)
                    {
                        cPtr->setValue(cPtr->getValue() % 10);
                        comp = true;
                    }
                    aPtr = aPtr->getNextNode();
                    // if (cPtr->getNextNode() == nullptr)
                    //     cPtr->setNextNode(new Node(0));
                    // cPtr = cPtr->getNextNode();
                }
                else
                {
                    // Add
                    cPtr->setValue(cPtr->getValue() + aPtr->getValue() + bPtr->getValue());
                    if (cPtr->getValue() / 10 > 0)
                    {
                        cPtr->setValue(cPtr->getValue() % 10);
                        comp = true;
                    }
                    aPtr = aPtr->getNextNode();
                    bPtr = bPtr->getNextNode();
                    // if (cPtr->getNextNode() == nullptr)
                    //     cPtr->setNextNode(new Node(0));
                    // cPtr = cPtr->getNextNode();
                }
                if (comp == true)
                {
                    cPtr->setNextNode(new Node(1));
                    cPtrPrev = cPtr;
                    cPtr = cPtr->getNextNode();
                    comp = false;
                }
            }
        }
        return BigInt(cPtrFront, cPtr);
    }
    BigInt mul(BigInt b) { return BigInt(0); }
    BigInt pow(int exp) { return BigInt(0); }
    char *toString()
    {
        char *result = nullptr;
        int length = 0;
        Node *ptr = this->front;

        while (ptr != nullptr)
        {
            ptr = ptr->getNextNode();
            length++;
        }

        ptr = this->front;
        result = new char[length + 1];
        for (int loop = length; loop > 0; loop--)
        {
            result[loop - 1] = ptr->getValue() + '0';
            ptr = ptr->getNextNode();
        }
        return result;
    }
};

int main(void)
{
    int l = 0;
    char *input = nullptr;

    scanf("%d", &l);
    input = new char[l + 1];
    scanf(" %s", input);

    if (l <= 5)
    {
        long long hash = 0;
        for (int loop = 0; loop < l; loop++)
            hash = hash + ((input[loop] - 'a') + 1) * (long long)pow(31, loop);
        printf("%lld", hash);
    }
    else
    {
        // BigInt Implementation
        BigInt hash(0);
        hash = hash.add(BigInt(100));
        //for (int loop = 0; loop < l; loop++)
        //    hash = hash.add(BigInt((input[loop] - 'a') + 1).mul(BigInt(31).pow(loop)));
        printf("%s", hash.toString());
    }
    return 0;
}