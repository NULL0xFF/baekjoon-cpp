#include <cstdio>
#include <cmath>

long long init(long long a[], long long tree[], int node, int start, int end)
{
    if (start == end)
        return tree[node] = a[start];
    else
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
long long sum(const long long tree[], int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(long long tree[], int node, int start, int end, int index, int diff)
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
    long long *A = nullptr, *tree = nullptr;
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);
    A = new long long[n + 1]();
    tree = new long long[(int)pow(2, ceil(log2(n)) + 1)]();

    init(A, tree, 1, 1, n); // Create Segment Tree
    {
        int c = 0, i = 0, k = 0;
        for (int loop = 0; loop < m; loop++)
        {
            scanf("%d %d %d", &c, &i, &k);
            if (c == 0) // Sum
            {
                if (i > k)
                    printf("%lld\n", sum(tree, 1, 1, n, k, i));
                else
                    printf("%lld\n", sum(tree, 1, 1, n, i, k));
            }
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