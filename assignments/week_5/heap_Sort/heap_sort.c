

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Heapify function
void heapify(int arr[], int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && arr[left] > arr[largest])
        largest = left;


    if (right < n && arr[right] > arr[largest])
        largest = right;


    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;


        heapify(arr, n, largest);
    }
}


// Heap Sort function
void heapSort(int arr[], int n)
{
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }


    // Delete maximum repeatedly
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;


        heapify(arr, i, 0);
    }
}


// Generate random array
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}


// Generate ascending sorted array
void generateAscendingArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}


// Generate descending sorted array
void generateDescendingArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}


// Copy array
void copyArray(int source[], int destination[], int n)
{
    for (int i = 0; i < n; i++)
    {
        destination[i] = source[i];
    }
}


// Measure execution time
double calculateTime(int arr[], int n)
{
    clock_t start, end;

    start = clock();

    heapSort(arr, n);

    end = clock();


    return ((double)(end - start)) / CLOCKS_PER_SEC;
}



int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);


    int original[n];
    int temp[n];


    srand(time(0));


    // Random Array Test
    generateRandomArray(original, n);

    copyArray(original, temp, n);

    printf("\nRandom Array Execution Time: %lf seconds",
           calculateTime(temp, n));



    // Ascending Array Test
    generateAscendingArray(original, n);

    copyArray(original, temp, n);

    printf("\nAscending Array Execution Time: %lf seconds",
           calculateTime(temp, n));



    // Descending Array Test
    generateDescendingArray(original, n);

    copyArray(original, temp, n);

    printf("\nDescending Array Execution Time: %lf seconds",
           calculateTime(temp, n));


    return 0;
}
