# Divide and Conquer

## 4 Median of Two Sorted Arrays

## 23 Merge k Sorted Lists

## 53 Maximum Subarray

## 169 Majority Element

## 215 Kth Largest Element in an Array
**Description**

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

You may assume k is always valid, 1 ≤ k ≤ array's length.

**Solution 1**

Sort the array first, then return the kth largest element. 

**Solution 2**

Firstly, find the maximum and minimum of the array. Then use `binary search` to find the kth largest element. Suppose range and length of the array are $R$ and $N$, respectively. The time complexity is $N \log_2 R$. 

```cpp
int findKthLargest(vector<int>& nums, int k) {
    int min = nums[0], max = nums[0];
    for (int num : nums) {
        if (num < min) { min = num; }
        else if (num > max) { max = num; }
    }

    int l = min, r = max;
    while (l <= r) {
        int mid = (l + r) / 2;
        int nGreater = 0, nEqual = 0;
        for (int num : nums) {
            if (num > mid) { ++nGreater; }
            else if (num == mid) { ++nEqual; }
        }

        if (nGreater >= k) {
            l = mid + 1;
        }
        else {
            if (nGreater + nEqual >= k) { return mid; }
            else { r = mid - 1; }
        }
    }

    return l;
}
```

## 240 Search a 2D Matrix II
**Description**

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.

**Solution**

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    auto& m = matrix;
    if (m.empty() || m[0].empty()) {
        return false;
    }
    
    int minR = 0, maxR = m.size() - 1;
    int minC = 0, maxC = m[0].size() - 1;
    while (minR <= maxR && minC <= maxC) {
        int rt = m[minR][maxC]; // right top
        if (rt < target) {
            ++minR;
        }
        else if (rt > target) {
            --maxC;
        }
        else {
            return true;
        }
        
        int lb = m[maxR][minC]; // left bottom
        if (lb < target) {
            ++minC;
        }
        else if (lb > target) {
            --maxR;
        }
        else {
            return true;
        }
    }
    
    return false;
}
```