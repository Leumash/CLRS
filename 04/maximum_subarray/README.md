# Solved using divide and conquer

Given an array A[low..high], split A into two subarrays to A[low..mid] and A[mid + 1..high]

Then the maximum subarray must be in one of three locations:

1. Entirely in the subarray A[low..mid]
2. Entirely in the subarray A[mid + 1..high]
3. Crossing the midpoint

The recurrence is:

T(n) = { O(1) if n = 1
       { 2T(n/2) + O(n) if n > 2

Runtime is O(n log n)
