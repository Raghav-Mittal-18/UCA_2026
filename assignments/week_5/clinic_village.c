#include <stdio.h>

#define MAX 1000

typedef struct
{
    int population;
    int clinics;
    double load;
} Village;

Village heap[MAX];
int size = 0;

void swap(Village *a, Village *b)
{
    Village temp = *a;
    *a = *b;
    *b = temp;
}

void insert(Village v)
{
    int i = size++;
    heap[i] = v;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[parent].load >= heap[i].load)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

Village deleteMax()
{
    Village max = heap[0];
    heap[0] = heap[--size];

    int i = 0;

    while (2 * i + 1 < size)
    {
        int child = 2 * i + 1;

        if (child + 1 < size && heap[child + 1].load > heap[child].load)
            child++;

        if (heap[i].load >= heap[child].load)
            break;

        swap(&heap[i], &heap[child]);
        i = child;
    }

    return max;
}

int main()
{
    int n, k;

    printf("Enter number of villages: ");
    scanf("%d", &n);

    printf("Enter total clinics: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        Village v;

        printf("Population of village %d: ", i + 1);
        scanf("%d", &v.population);

        v.clinics = 1;
        v.load = (double)v.population;

        insert(v);
    }

    int extra = k - n;

    while (extra--)
    {
        Village v = deleteMax();

        v.clinics++;
        v.load = (double)v.population / v.clinics;

        insert(v);
    }

    printf("\nMinimum Possible Maximum Load = %.2f\n", heap[0].load);

    return 0;
}
