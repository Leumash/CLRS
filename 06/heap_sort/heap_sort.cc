#include <iostream>

using namespace std;

void maxHeapify(int arr[], int pos, int n) {
    int max = pos;
    int left = pos * 2;
    int right = pos * 2 + 1;
    if (left < n) {
        max = arr[left] < arr[pos] ? pos : left;
    }
    if (right < n) {
        max = arr[right] < arr[max] ? max : right;
    }
    if (max != pos) {
        swap(arr[max], arr[pos]);
        maxHeapify(arr, max, n);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i=n-1; i >= 0; --i) {
        maxHeapify(arr, i, n);
    }
}

void heap_sort(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}

int main() {
    int arr[] = {5, 2, 3, 8, 1, 7, 4, 6, 9, 10};
    for (auto i =  begin(arr); i != end(arr); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
    heap_sort(arr, 10);
    for (auto i =  begin(arr); i != end(arr); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
    return 0;
}

