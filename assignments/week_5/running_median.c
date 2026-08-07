#include <stdio.h>

#define MAX 1000

int maxHeap[MAX];
int minHeap[MAX];

int maxSize = 0;
int minSize = 0;


// Function to swap two values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Insert element into Max Heap
void insertMax(int value)
{
    int i = maxSize++;
    maxHeap[i] = value;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (maxHeap[parent] >= maxHeap[i])
            break;

        swap(&maxHeap[parent], &maxHeap[i]);
        i = parent;
    }
}


// Remove maximum element from Max Heap
int removeMax()
{
    int value = maxHeap[0];

    maxHeap[0] = maxHeap[--maxSize];

    int i = 0;

    while (2 * i + 1 < maxSize)
    {
        int child = 2 * i + 1;

        if (child + 1 < maxSize &&
            maxHeap[child + 1] > maxHeap[child])
            child++;

        if (maxHeap[i] >= maxHeap[child])
            break;

        swap(&maxHeap[i], &maxHeap[child]);
        i = child;
    }

    return value;
}


// Insert element into Min Heap
void insertMin(int value)
{
    int i = minSize++;
    minHeap[i] = value;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (minHeap[parent] <= minHeap[i])
            break;

        swap(&minHeap[parent], &minHeap[i]);
        i = parent;
    }
}


// Remove minimum element from Min Heap
int removeMin()
{
    int value = minHeap[0];

    minHeap[0] = minHeap[--minSize];

    int i = 0;

    while (2 * i + 1 < minSize)
    {
        int child = 2 * i + 1;

        if (child + 1 < minSize &&
            minHeap[child + 1] < minHeap[child])
            child++;

        if (minHeap[i] <= minHeap[child])
            break;

        swap(&minHeap[i], &minHeap[child]);
        i = child;
    }

    return value;
}


// Insert number from stream
void insert(int num)
{
    if (maxSize == 0 || num <= maxHeap[0])
        insertMax(num);
    else
        insertMin(num);


    // Balance both heaps
    if (maxSize > minSize + 1)
    {
        insertMin(removeMax());
    }
    else if (minSize > maxSize)
    {
        insertMax(removeMin());
    }
}


// Return current median
float getMedian()
{
    if (maxSize == minSize)
    {
        return (maxHeap[0] + minHeap[0]) / 2.0;
    }

    return maxHeap[0];
}


int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter stream elements:\n");

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);

        insert(num);

        printf("Median = %.2f\n", getMedian());
    }

    return 0;
}
