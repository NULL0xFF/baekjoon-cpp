#ifndef NODE_HPP
#define NODE_HPP
class Node
{
private:
    Node *left = nullptr, *right = nullptr;
    int value = 0;

public:
    Node() : Node(0, nullptr, nullptr) {}
    Node(int val) : Node(val, nullptr, nullptr) {}
    Node(int val, Node *leftPtr, Node *rightPtr) : value(val), left(leftPtr), right(rightPtr) {}
    Node *getLeft(void) { return this->left; }
    Node *getRight(void) { return this->right; }
    int getValue(void) { return this->value; }
    void setLeft(Node *ptr) { this->left = ptr; }
    void setRight(Node *ptr) { this->right = ptr; }
    void setValue(int val) { this->value = val; }
};
#endif // NODE_HPP