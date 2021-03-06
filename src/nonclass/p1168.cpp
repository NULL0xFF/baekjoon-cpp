#include <cstdio>
#include <cmath>

int init(int input[], int tree[], int node, int start, int end)
{
    if (start == end)
        return tree[node] = input[start];
    int mid = (start + end) / 2;
    int left = init(input, tree, node * 2, start, mid);
    int right = init(input, tree, (node * 2) + 1, mid + 1, end);
    return tree[node] = left + right;
}

/* Update tree[node] with diff from root to leaf */
int update(int tree[], int node, int start, int end, int index, int diff)
{
    tree[node] = tree[node] + diff; // Update value
    if (start == end)
        return 0;
    int mid = (start + end) / 2;
    if (index <= mid)
        /* Left Subtree Update */
        return update(tree, node * 2, start, mid, index, diff);
    else
        /* Right Subtree Update */
        return update(tree, (node * 2) + 1, mid + 1, end, index, diff);
}

/* Check Left Subtree(tree[node * 2]) if finding index is correct */
int query(int tree[], int node, int start, int end, int index)
{
    if (start == end)
        return start;
    int mid = (start + end) / 2;
    if (index <= tree[node * 2])
        return query(tree, node * 2, start, mid, index);
    else
        return query(tree, (node * 2) + 1, mid + 1, end, index - tree[node * 2]);
}

int main(void)
{
    // Variables
    int n = 0, k = 0;
    scanf("%d %d", &n, &k); // Input
    int input[n + 1] = {};
    for (int index = 1; index <= n; index++)
        input[index] = 1;
    int tree[(int)pow(2, ceil(log2(n)) + 1)] = {};

    // Initialize Segment Tree with value 1
    init(input, tree, 1, 1, n);

    // Josephus Problem
    {
        int index = 1; // Start Point
        printf("<");
        for (int loop = 0; loop < n; loop++)
        {
            int size = n - loop;     // Current count of leaves of tree
            index = index + (k - 1); // Move clockwise
            if (index % size == 0)
                index = size; // Calibration index as size for get leaf index
            else if (index > size)
                index = index % size;              // Out of boundary, josephus-ing (CiRCLING)
            int num = query(tree, 1, 1, n, index); // Query tree to get order
            update(tree, 1, 1, n, num, -1);        // Change the leaf node value to 0 and update tree
            if (loop == (n - 1))
                printf("%d", num); // Last Query
            else
                printf("%d, ", num); // On-going Query
        }
        printf(">\n");
    }
    return 0;
}