#include <iostream>

using namespace std;

int partition(int arr[], int start, int end) {
    int lessThanSplitIndex = start - 1;
    int splitValue = arr[end];
    for (int i=start; i<end; ++i) {
        if (arr[i] < splitValue) {
            ++lessThanSplitIndex;
            swap(arr[i], arr[lessThanSplitIndex]);
        }
    }
    int split = lessThanSplitIndex + 1;
    swap(arr[end], arr[split]);
    return split;
}

void quicksort(int arr[], int start, int end) {
    if (start + 1 > end) {
        return;
    }
    int split = partition(arr, start, end);
    quicksort(arr, start, split - 1);
    quicksort(arr, split + 1, end);
}

void quicksort(int arr[], int n) {
    quicksort(arr, 0, n - 1);
}

int main() {
    int arr[] = {3, 9, 2, 5, 6, 4, 8, 7, 1, 10};
    for (auto i = begin(arr); i != end(arr); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
    quicksort(arr, 10);
    for (auto i = begin(arr); i != end(arr); ++i) {
        cout << *i << ' ';
    }
    return 0;
}

