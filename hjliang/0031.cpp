/**
 * 31. Next Permutation
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 */

/**
 * Runtime: 8 ms, faster than 82.63% of C++ online submissions for Next Permutation.
 * Memory Usage: 8.6 MB, less than 35.34% of C++ online submissions for Next Permutation.
 * md 看不懂题  https://blog.csdn.net/yimi1995/article/details/77115866
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size() - 1;
        int tmp = size;
        for (; tmp > 0; --tmp) {
            if (nums[tmp] > nums[tmp - 1])
                break;
        }
        if (tmp == 0)
            reverse(nums.begin(),nums.end());
        else {
            int larger = size;
            tmp -= 1;
            while (nums[tmp] >= nums[larger])
                --larger;
            swap(nums, tmp, larger);
            sort(nums.begin() + tmp + 1,nums.end());
            cout << tmp << " " << larger << endl;
        }
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};