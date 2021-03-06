#ifndef NODE_HPP
#define NODE_HPP
template <typename Type>
class Node
{
private:
    Node *left = nullptr, *right = nullptr;
    Type value = 0;

public:
    Node() : Node(nullptr, nullptr, nullptr) {}
    Node(Type val) : Node(val, nullptr, nullptr) {}
    Node(Type val, Node *leftPtr, Node *rightPtr) : value(val), left(leftPtr), right(rightPtr) {}
    Node *getLeft(void) { return this->left; }
    Node *getRight(void) { return this->right; }
    Type getValue(void) { return this->value; }
    void setLeft(Node *ptr) { this->left = ptr; }
    void setRight(Node *ptr) { this->right = ptr; }
    void setValue(Type val) { this->value = val; }
};
#endif // NODE_HPP