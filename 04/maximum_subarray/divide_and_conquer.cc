#include <iostream>
#include <algorithm>

using namespace std;

int combine(int arr[], int start, int middle, int end) {
    int maxLeft = arr[middle];
    int maxRight = arr[middle + 1];
    int current = maxLeft;
    for (int i=middle-1; i >= start; --i) {
        current += arr[i];
        maxLeft = max(current, maxLeft);
    }
    current = maxRight;
    for (int i=middle+2; i <= end; ++i) {
        current += arr[i];
        maxRight = max(current, maxRight);
    }
    return maxLeft + maxRight;
}

int getMaximumSubarray(int arr[], int start, int end) {
    if (end - start == 1) {
        return arr[start];
    }
    int middle = (end - start) / 2 + start;
    int left = getMaximumSubarray(arr, start, middle);
    int right = getMaximumSubarray(arr, middle + 1, end);
    int both = combine(arr, start, middle, end);
    return max(max(left, right), both);
}

int getMaximumSubarray(int arr[], int n) {
    getMaximumSubarray(arr, 0, n-1);
}

int main() {
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << getMaximumSubarray(arr, 8) << endl;
}

