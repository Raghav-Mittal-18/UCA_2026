#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
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

// Quickselect
void quickSelect(int arr[], int low, int high, int k)
{
    if (low < high)
    {
        int pos = partition(arr, low, high);

        if (pos == k)
            return;

        else if (pos > k)
            quickSelect(arr, low, pos - 1, k);

        else
            quickSelect(arr, pos + 1, high, k);
    }
}

// Generate random data
void generateArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}


int main()
{
    srand(time(NULL));

    int sizes[] = {
        1000,
        5000,
        10000,
        20000,
        40000,
        80000
    };

    int total = 6;


    printf("Dataset Size\tRuntime(seconds)\n");
    printf("--------------------------------\n");


    for(int i = 0; i < total; i++)
    {
        int n = sizes[i];

        int *arr = malloc(n * sizeof(int));


        generateArray(arr, n);


        // K = 10% of dataset
        int k = n / 10;


        clock_t start = clock();


        quickSelect(arr, 0, n-1, k-1);


        clock_t end = clock();


        double time =
        ((double)(end-start))/CLOCKS_PER_SEC;


        printf("%d\t\t%lf\n", n, time);


        free(arr);
    }


    return 0;
}
