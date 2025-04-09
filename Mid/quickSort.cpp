#include <iostream>
using namespace std;

void printArray(int arr[], int low, int high) {
    cout << "[ ";
    for (int i = low; i <= high; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int partition(int *a, int low, int high) {
    int pivot = a[low];
    int left = low;
    int right = high;

    while (left < right) {
        while (left <= high && a[left] <= pivot) {
            left++;
        }
        while (a[right] > pivot) {
            right--;
        }
        if (left < right) {
            swap(a[left], a[right]);
        }
    }
    swap(a[low], a[right]);
    return right;
}

void quicksort(int *a, int low, int high) {
    if (low < high) {
        cout << "Before Partition: ";
        printArray(a, low, high);

        int pivot = partition(a, low, high);

        cout << "After Partition:  ";
        printArray(a, low, pivot - 1);
        cout << " [ " << a[pivot] << " ] ";
        printArray(a, pivot + 1, high);
        cout << endl;

        quicksort(a, low, pivot - 1);
        quicksort(a, pivot + 1, high);
    }
}

int main() {
    int a[] = {18, 12, 15, 42, 38, 36, 29, 27};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original Array: ";
    printArray(a, 0, n - 1);

    quicksort(a, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(a, 0, n - 1);
    cout << endl;

    return 0;
}
