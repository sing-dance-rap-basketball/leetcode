/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start

/**
 * Accepted
 *  200/200 cases passed (0 ms) 
 *  Your runtime beats 100 % of cpp submissions
 *  Your memory usage beats 100 % of cpp submissions (5.9 MB)
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans(n, '0');
        
        vector<int> nums(n, 1);
        for (int i = 0; i < n; ++i) {
            nums[i] += i;
        }

        --k;
        for (int i = n; i > 0; ) {
            int fac = factorial(--i);
            ans[n - 1 - i] += nums[k / fac];
            nums.erase(nums.begin() + (k / fac));
            k %= fac;
        }

        return ans;
    }

    int factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorial(n-1);
    }
};
// @lc code=end

/*
string getPermutation(int n, int k) {
    string ans(n, '0');
    
    vector<int> nums(n, 1);
    for (int i = 0; i < n; ++i) {
        nums[i] += i;
    }

    vector<int> factorial(n+1, 1);
    for (int i = 2; i <= n; ++i) {
        factorial[i] = factorial[i-1] * i;
    }

    for (int i = n-1, j = k-1; i >= 0; --i) {
        ans[n - 1 - i] += nums[j / factorial[i]];
        nums.erase(nums.begin() + (j / factorial[i]));
        j %= factorial[i];
    }

    return ans;
}
*/