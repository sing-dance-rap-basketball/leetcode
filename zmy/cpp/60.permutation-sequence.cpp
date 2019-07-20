/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        int table[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string nums = "123456789";
        string result;
        --k;
        for (int i = n; i >= 1; --i) {
            int j = k / table[i - 1];
            k %= table[i - 1];
            result.push_back(nums[j]);
            nums.erase(nums.begin() + j);
        }
        return result;
    }
};

