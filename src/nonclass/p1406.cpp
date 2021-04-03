#include <cstdio>

template <typename Type>
class Node
{
private:
    Node *left = nullptr, *right = nullptr;
    Type value = NULL;

public:
    Node(Type val = NULL, Node *leftPtr = nullptr, Node *rightPtr = nullptr) : value(val), left(leftPtr), right(rightPtr) {}
    Node *getLeft(void) { return this->left; }
    Node *getRight(void) { return this->right; }
    Type getValue(void) { return this->value; }
    void setLeft(Node *ptr) { this->left = ptr; }
    void setRight(Node *ptr) { this->right = ptr; }
    void setValue(Type val) { this->value = val; }
};

int main(void)
{
    Node<char> *stringHeader = new Node<char>('\0');
    Node<char> *cursor = new Node<char>('\0', stringHeader);
    stringHeader->setRight(cursor);
    int numberOfOperation = 0;
    char c = '\0';

    while ((c = getchar()) != '\n')
    {
        cursor->getLeft()->setRight(new Node<char>(c, cursor->getLeft(), cursor));
        cursor->setLeft(cursor->getLeft()->getRight());
    }

    scanf("%d", &numberOfOperation);

    for (int loop = 0; loop < numberOfOperation; loop++)
    {
        char opcode = '\0';
        scanf(" %c", &opcode);
        switch (opcode)
        {
        case 'L':
            if (cursor->getLeft() != nullptr)
            {
                cursor->getRight()->setLeft(cursor->getLeft());
                cursor->getLeft()->setRight(cursor->getRight());
                cursor->setRight(cursor->getLeft());
                cursor->setLeft(cursor->getLeft()->getLeft());
                cursor->getRight()->setLeft(cursor);
                if (cursor->getLeft() != nullptr)
                    cursor->getLeft()->setRight(cursor);
            }
            break;
        case 'D':
            break;
        case 'B':
            break;
        case 'P':
            break;
        }
    }

    Node<char> *ptr = stringHeader;
    while (ptr != nullptr)
    {
        if (ptr->getValue() != '\0')
            printf("%c", ptr->getValue());
        ptr = ptr->getRight();
    }
    printf("\n");
    return 0;
}