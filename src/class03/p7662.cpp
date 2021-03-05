#include <cstdio>
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
class DoublePriorityQueue
{
private:
    Node *low = nullptr, *high = nullptr;

public:
    DoublePriorityQueue() {}
    void push(const int i)
    {
        if (low == nullptr)
        {
            low = new Node(i);
            high = low;
        }
        else
        {
            if (i <= low->getValue())
            {
                low->setLeft(new Node(i, nullptr, low));
                low = low->getLeft();
            }
            else if (high->getValue() <= i)
            {
                high->setRight(new Node(i, high, nullptr));
                high = high->getRight();
            }
            else
            {
                Node *ptr = low, *temp = nullptr;
                while (ptr != nullptr)
                {
                    if (ptr->getValue() <= i && i < ptr->getRight()->getValue())
                    {
                        temp = new Node(i, ptr, ptr->getRight());
                        temp->getRight()->setLeft(temp);
                        ptr->setRight(temp);
                        temp = nullptr;
                        break;
                    }
                    ptr = ptr->getRight();
                }
            }
        }
    }
    int pop(int priority)
    {
        if (empty())
            return 0;
        Node *ptr = nullptr;
        if (high == low)
        {
            ptr = high;
            high = nullptr;
            low = nullptr;
        }
        else if (priority == 1)
        {
            ptr = high;
            high = high->getLeft();
            high->setRight(nullptr);
        }
        else if (priority == -1)
        {
            ptr = low;
            low = low->getRight();
            low->setLeft(nullptr);
        }
        int value = ptr->getValue();
        delete (ptr);
        return value;
    }
    bool empty() { return (high == nullptr && low == nullptr); }
    int top() { return high->getValue(); }
    int bottom() { return low->getValue(); }
};
int main(void)
{
    int t = 0;
    scanf("%d", &t);
    for (int test = 0; test < t; test++)
    {
        int k = 0;
        scanf("%d", &k);
        {
            DoublePriorityQueue Q;
            int n = 0;
            char c = '\0';
            for (int loop = 0; loop < k; loop++)
            {
                scanf(" %c %d", &c, &n);
                if (c == 'I')
                    Q.push(n);
                else if (c == 'D')
                    Q.pop(n);
            }
            if (Q.empty())
                printf("EMPTY\n");
            else
                printf("%d %d\n", Q.top(), Q.bottom());
        }
    }
    return 0;
}