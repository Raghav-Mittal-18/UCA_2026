#include <stdio.h>

int merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int count=0;
    int L[n1], R[n2];
    // Copy data to temporary arrays ,baad me sort krne ke liye
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    int b=mid+1;
    // count the pairs here before merge
    for (int a=left;a<=mid;a++){

        while (b<=right && arr[a]> arr[b]) b++;
        count += b-(mid+1);
    }
    // Merge the temporary arrays
    while (i < n1 && j < n2) {
        // if (L[i]>2*R[j]) count++;
        if (L[i] <= R[j]) {
            
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}

int mergeSort(int arr[], int left, int right) {
    int count=0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count+=mergeSort(arr, left, mid);
        count+=mergeSort(arr, mid + 1, right);

        count+=merge(arr, left, mid, right);
    }
    return count;
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n",mergeSort(arr, 0, n - 1));

    return 0;
}
