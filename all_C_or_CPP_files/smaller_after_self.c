#include <stdio.h>

#define MAX 100000

int arr[MAX], idx[MAX];
int tempArr[MAX], tempIdx[MAX];
int ans[MAX];

void merge(int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    int count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[j] < arr[i])
        {
            tempArr[k] = arr[j];
            tempIdx[k] = idx[j];
            count++;
            j++;
        }
        else
        {
            ans[idx[i]] += count;
            tempArr[k] = arr[i];
            tempIdx[k] = idx[i];
            i++;
        }
        k++;
    }

    while (i <= mid)
    {
        ans[idx[i]] += count;
        tempArr[k] = arr[i];
        tempIdx[k] = idx[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        tempArr[k] = arr[j];
        tempIdx[k] = idx[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = tempArr[i];
        idx[i] = tempIdx[i];
    }
}

void mergeSort(int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    merge(left, mid, right);
}

int main()
{
    int n = 0;

    while (scanf("%d\n", &arr[n]) == 1)
    {
        idx[n] = n;
        n++;
    }
    printf("\n");
    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
