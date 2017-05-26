/*
Rewrite the MERGE procedure so that it does not use sentinels, instead stopping once either array L or R has had all its elements copied back to A and then copying the remainder of the other array back into A.
*/

#include <iostream>
#include <algorithm>

using namespace std;

void merge(int arr[], int start, int middle, int end) {
    int n1 = middle - start;
    int n2 = end - middle;
    int left[n1];
    int right[n2];
    for (int i=0; i<n1; ++i) {
        left[i] = arr[i + start];
    }
    for (int i=0; i<n2; ++i) {
        right[i] = arr[i + middle];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            ++i;
        } else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = left[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}

void print(string message, int* begin, int* end) {
    cout << message << ' ';
    for (int* i=begin; i != end; ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    int arr[] = {1,3,5,7,9,  2,4,6,8,10};
    print("Before: ", begin(arr), end(arr));
    merge(arr, 0, 5, 10);
    print("After:  ", begin(arr), end(arr));

    int arr2[] = {0,0,0, 1,6,9,10,40, 1,2,2,3,8,10,12, 0,0,0};
    print("Before: ", begin(arr2), end(arr2));
    merge(arr2, 3, 8, 15);
    print("After:  ", begin(arr2), end(arr2));
}

