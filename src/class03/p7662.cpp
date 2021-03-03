#include <cstdio>

class DPriorityQueue
{
private:
    class DoubleNode
    {
    private:
        int value = 0;
        DoubleNode *next = nullptr;
        DoubleNode *prev = nullptr;

    public:
        DoubleNode() : DoubleNode(0, nullptr, nullptr) {}
        DoubleNode(int val) : DoubleNode(val, nullptr, nullptr) {}
        DoubleNode(int val, DoubleNode *nextPtr) : DoubleNode(val, nextPtr, nullptr) {}
        DoubleNode(int val, DoubleNode *nextPtr, DoubleNode *prevPtr)
        {
            this->value = val;
            this->next = nextPtr;
            this->prev = prevPtr;
        }
        int getValue(void) { return this->value; }
        DoubleNode *getNext(void) { return this->next; }
        DoubleNode *getPrev(void) { return this->prev; }
        void setValue(int val) { this->value = val; }
        void setNext(DoubleNode *ptr) { this->next = ptr; }
        void setPrev(DoubleNode *ptr) { this->prev = ptr; }
    };
    DoubleNode *front = nullptr, *end = nullptr;

public:
    DPriorityQueue() {}
    void push(int val)
    {
        if (empty())
        {
            this->front = new DoubleNode(val);
            this->end = this->front;
        }
        else
        {
            this->end->setNext(new DoubleNode(val, nullptr, this->end));
            this->end = this->end->getNext();
        }
    }
    void pop(int priority)
    {
        if (empty())
            return;
        else if (priority == 1)
        {
            DoubleNode *high = this->getHigh();
            if (high == this->front)
            {
                this->front = high->getNext();
                if (this->front == nullptr)
                    this->end == nullptr;
                else
                    this->front->setPrev(nullptr);
            }
            else if (high == this->end)
            {
                this->end = this->end->getPrev();
                this->end->setNext(nullptr);
            }
            else
                high->getPrev()->setNext(high->getNext());
            delete (high);
        }
        else if (priority == -1)
        {
            DoubleNode *low = this->getLow();
            if (low == this->front)
            {
                this->front = low->getNext();
                if (this->front == nullptr)
                    this->end == nullptr;
                else
                    this->front->setPrev(nullptr);
            }
            else if (low == this->end)
            {
                this->end = this->end->getPrev();
                this->end->setNext(nullptr);
            }
            else
                low->getPrev()->setNext(low->getNext());
            delete (low);
        }
    }
    DoubleNode *getHigh(void)
    {
        DoubleNode *ptr = this->front;
        DoubleNode *high = ptr;
        while (ptr != nullptr)
        {
            if (high->getValue() < ptr->getValue())
                high = ptr;
            ptr = ptr->getNext();
        }
        return high;
    }
    DoubleNode *getLow(void)
    {
        DoubleNode *ptr = this->front;
        DoubleNode *low = ptr;
        while (ptr != nullptr)
        {
            if (ptr->getValue() < low->getValue())
                low = ptr;
            ptr = ptr->getNext();
        }
        return low;
    }
    bool empty() { return this->front == nullptr; }
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
            DPriorityQueue Q;
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
                printf("%d %d\n", Q.getHigh()->getValue(), Q.getLow()->getValue());
        }
    }
    return 0;
}