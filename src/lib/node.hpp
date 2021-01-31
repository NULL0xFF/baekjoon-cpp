#ifndef NODE_HPP
#define NODE_HPP

template <typename Type>
class Node
{
private:
    Type value;
    Node<Type> *nextNode;

public:
    Node()
    {
        this->value = NULL;
        this->nextNode = nullptr;
    }
    Node(Type value)
    {
        this->value = NULL;
        this->nextNode = nullptr;
    }
    Node(Type value, Node<Type> *nextNode)
    {
        this->value = NULL;
        this->nextNode = nullptr;
    }
    Type getValue(void) { return this->value; }
    Node<Type> *getNextNode(void) { return this->nextNode; }
    void setValue(Type newValue) { this->value = newValue; }
    void setNextNode(Node<Type> *newNextNode) { this->nextNode = newNextNode; }
};

#endif // NODE_HPP