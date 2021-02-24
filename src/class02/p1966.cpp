#include <cstdio>
#include <utility>

class PriorityQueue
{
private:
    class PriorityNode
    {
    private:
        PriorityNode *next = nullptr;
        int value = 0;
        int priority = 0;

    public:
        PriorityNode() : PriorityNode(-1, -1) {}
        PriorityNode(int i, int p) : PriorityNode(i, p, nullptr) {}
        PriorityNode(int i, int p, PriorityNode *ptr)
        {
            value = i;
            priority = p;
            next = ptr;
        }
        PriorityNode *getNext() { return next; }
        int getValue() { return value; }
        int getPriority() { return priority; }
        void setNext(PriorityNode *ptr) { next = ptr; }
        void setValue(int i) { value = i; }
        void setPriority(int p) { priority = p; }
    };
    PriorityNode *frontPtr = nullptr, *endPtr = nullptr, *topPtr = nullptr;

public:
    PriorityQueue() {}
    void push(std::pair<int, int> p)
    {
        if (frontPtr == nullptr)
        {
            frontPtr = new PriorityNode(p.first, p.second);
            topPtr = endPtr = frontPtr;
        }
        else
        {
            endPtr->setNext(new PriorityNode(p.first, p.second));
            endPtr = endPtr->getNext();
            if (topPtr->getPriority() < endPtr->getPriority())
                topPtr = endPtr;
        }
    }
    std::pair<int, int> pop()
    {
        if (frontPtr == nullptr)
            return std::make_pair(-1, -1);
        PriorityNode *popPtr = frontPtr;
        frontPtr = frontPtr->getNext();
        if (popPtr == topPtr)
        {
            PriorityNode *nextTopPtr = frontPtr, *ptr = frontPtr;
            while (ptr != nullptr)
            {
                if (nextTopPtr->getPriority() < ptr->getPriority())
                    nextTopPtr = ptr;
                ptr = ptr->getNext();
            }
            topPtr = nextTopPtr;
        }
        return std::make_pair(popPtr->getValue(), popPtr->getPriority());
    }
    int size()
    {
        if (empty())
            return 0;
        PriorityNode *ptr = frontPtr;
        int count = 0;
        while (ptr != nullptr)
        {
            count++;
            ptr = ptr->getNext();
        }
        return count;
    }
    bool empty() { return frontPtr == nullptr ? true : false; }
    std::pair<int, int> front() { return empty() ? std::make_pair(-1, -1) : std::make_pair(frontPtr->getValue(), frontPtr->getPriority()); }
    std::pair<int, int> back() { return empty() ? std::make_pair(-1, -1) : std::make_pair(endPtr->getValue(), endPtr->getPriority()); }
    std::pair<int, int> top() { return empty() ? std::make_pair(-1, -1) : std::make_pair(topPtr->getValue(), topPtr->getPriority()); }
};

void printerQueue()
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    PriorityQueue pQueue;
    for (int index = 0, input = 0; index < n; index++)
    {
        scanf("%d", &input);
        pQueue.push(std::make_pair(index, input));
    }
    int offset = 1;
    while (!pQueue.empty())
    {
        if (pQueue.front().second == pQueue.top().second)
        {
            if (pQueue.front().first == m)
            {
                printf("%d\n", offset);
                return;
            }
            else
                pQueue.pop();
            offset++;
        }
        else
            pQueue.push(pQueue.pop());
    }
    return;
}

int main(void)
{
    int t = 0;
    scanf("%d", &t);
    for (int loop = 0; loop < t; loop++)
        printerQueue();
    return 0;
}