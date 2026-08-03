#include <stdio.h>

// Swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (same as Quicksort)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

// Quickselect function
void quickSelect(int arr[], int low, int high, int k)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        if (p == k)
            return;
        else if (p > k)
            quickSelect(arr, low, p - 1, k);
        else
            quickSelect(arr, p + 1, high, k);
    }
}

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    if (k <= 0 || k > n)
    {
        printf("Invalid K\n");
        return 0;
    }

    // Rearrange so first k elements are the k smallest
    quickSelect(arr, 0, n - 1, k - 1);

    printf("\nSmallest %d elements (any order):\n", k);
    for (int i = 0; i < k; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return ;
}
