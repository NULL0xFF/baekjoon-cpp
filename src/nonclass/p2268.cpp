#include <cstdio>
#include <cmath>

// acmicpc.net/blog/view/9
int init(int a[], int tree[], int node, int start, int end)
{
    if (start == end)
        return tree[node] = a[start];
    else
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
int sum(const int tree[], int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int tree[], int node, int start, int end, int index, int diff)
{
    if (index < start || index > end)
        return;
    tree[node] = tree[node] + diff;
    if (start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

int main(void)
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int A[n + 1];
    int tree[(int)(pow(2, (((int)ceil(log2(n))) + 1)))];
    for (int index = 0; index <= n; index++)
        A[index] = 0;
    for (int index = 0; index < (int)(pow(2, (((int)ceil(log2(n))) + 1))); index++)
        tree[index] = 0;

    // Create Segment Tree
    init(A, tree, 1, 1, n);
    {
        int c = 0, i = 0, k = 0;
        for (int loop = 0; loop < m; loop++)
        {
            scanf("%d %d %d", &c, &i, &k);
            if (c == 0) // Sum
                printf("%d", sum(tree, 1, 1, n, i, k));
            else if (c == 1) // Modify
            {
                update(tree, 1, 1, n, i, k - A[i]);
                A[i] = k;
            }
            else // Command Error
                return 1;
        }
    }

    return 0;
}