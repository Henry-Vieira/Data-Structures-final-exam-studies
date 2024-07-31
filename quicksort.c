#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int j = left - 1;

    for (int i = left; i < right; i++) {
        if (arr[i] <= pivot) {
            j++;
            swap(&arr[j], &arr[i]);
        }
    }

    swap(&arr[j + 1], &arr[right]);
    return j + 1;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
    }
}

int main() {
    int arr[] = {1, 7, 9, 2, 0, 1, 4, 8, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}