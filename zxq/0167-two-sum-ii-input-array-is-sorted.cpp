/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

/*
    √ Accepted
    √ 17/17 cases passed (4 ms)
    √ Your runtime beats 97.6 % of cpp submissions
    √ Your memory usage beats 79.27 % of cpp submissions (9.4 MB)
 */
class Solution {
public:
    int FindTarget(vector<int>& nums, int target, int f, int b)
    {
        while (f <= b) {
            int m = (f + b) / 2;
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] > target) {
                b = m - 1;
            }
            else {
                f = m + 1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, 0);
        for (int i = 0; i < numbers.size() - 1; ++i) {
            int j = FindTarget(numbers, target-numbers[i], i+1, numbers.size()-1);
            if (j >= 0) {
                res[0] = i + 1;
                res[1] = j + 1;
                break;
            }
        }
        return res;
    }
};

