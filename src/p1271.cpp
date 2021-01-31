#include <cstdio>
#include <iostream>
#include <string>

template <typename Type>
class Node
{
private:
    Type value;
    Node<Type> *next;

public:
    Node()
    {
        this->value = NULL;
        this->next = nullptr;
    }
    Node(Type value)
    {
        this->value = value;
        this->next = nullptr;
    }
    Node(Type value, Node<Type> *next)
    {
        this->value = value;
        this->next = next;
    }
    Type getValue() { return this->value; }
    Node<Type> *getNextPtr() { return this->next; }
    void setValue(Type newValue) { this->value = newValue; }
    void setNextPtr(Node<Type> *newNextPtr) { this->next = newNextPtr; }
};

class BigInt
{
private:
    Node<char> *node;

public:
    BigInt()
    {
        node = new Node<char>(0);
    }
    BigInt(std::string s)
    {
        Node<char> *currPtr = nullptr;
        for (int loop = 0; loop < s.length(); loop++)
        {
            currPtr = new Node<char>(s[loop] - 48, currPtr);
        }
        node = currPtr;
    }
    std::string toString()
    {
        std::string s;
        Node<char> *ptr = node;
        while (true)
        {
            s.insert(0, std::string(1, ptr->getValue() + 48));
            if (ptr->getNextPtr() != nullptr)
                ptr = ptr->getNextPtr();
            else
                break;
        }
        return s;
    }
    void add(BigInt bInt)
    {
        Node<char> *aPtr = this->node, *bPtr = bInt.node, *tmpPtr = nullptr;
        bool carrierFlag = false;
        while (true)
        {
            if (aPtr != nullptr && bPtr != nullptr)
            {
                char tempChar = aPtr->getValue();
                aPtr->setValue((aPtr->getValue() + bPtr->getValue() + (carrierFlag ? 1 : 0)) % 10);
                carrierFlag = (tempChar + bPtr->getValue() + (carrierFlag ? 1 : 0)) / 10 >= 1 ? true : false;
            }
            else if (aPtr != nullptr && bPtr == nullptr)
            {
                while (aPtr != nullptr)
                {
                    char tempChar = aPtr->getValue();
                    aPtr->setValue((aPtr->getValue() + (carrierFlag ? 1 : 0)) % 10);
                    carrierFlag = (tempChar + (carrierFlag ? 1 : 0)) / 10 >= 1 ? true : false;
                    if (aPtr->getNextPtr() == nullptr)
                        tmpPtr = aPtr;
                    aPtr = aPtr->getNextPtr();
                }
                if (carrierFlag == true)
                    tmpPtr->setNextPtr(new Node<char>(1));
                break;
            }
            else if (aPtr == nullptr && bPtr != nullptr)
            {
                Node<char> *tmpNode = nullptr;
                aPtr = tmpPtr;
                while (bPtr != nullptr)
                {
                    tmpNode = new Node<char>(bPtr->getValue() + (carrierFlag == true ? 1 : 0) % 10);
                    carrierFlag = (((bPtr->getValue() + (carrierFlag ? 1 : 0)) / 10) == 0 ? false: true);
                    aPtr->setNextPtr(tmpNode);
                    aPtr = aPtr->getNextPtr();
                    bPtr = bPtr->getNextPtr();
                }
                if (carrierFlag == true)
                    aPtr->setNextPtr(new Node<char>(1));
                break;
            }
            else
            {
                break;
            }
            // Next Ptr
            if (aPtr->getNextPtr() == nullptr)
                tmpPtr = aPtr;
            aPtr = aPtr->getNextPtr();
            bPtr = bPtr->getNextPtr();
        }
    }
    BigInt divide(BigInt bInt)
    {
        
    }
};

int main(int argc, char *argv[])
{
    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;
    BigInt *b1 = new BigInt(s1);
    BigInt *b2 = new BigInt(s2);
    b1->add(*b2);
    std::cout << b1->toString() << std::endl;
    return 0;
}