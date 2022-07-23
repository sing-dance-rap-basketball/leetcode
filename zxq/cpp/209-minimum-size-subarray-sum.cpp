/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

/*
    √ Accepted
    √ 15/15 cases passed (8 ms)
    √ Your runtime beats 96.58 % of cpp submissions
    √ Your memory usage beats 94.12 % of cpp submissions (9.9 MB)
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) { return 0; }

        int ans;
        int len = nums.size();
        int slow = 0, fast = 0; // two pointers
        int currSum;
        for(currSum = nums[0]; 
            fast+1 < len && currSum < s;
            ++fast, currSum += nums[fast]);
        if (currSum < s) { return 0; }
        ans = fast - slow + 1;
        
        do {
            for (; fast+1 < len && currSum < s; currSum += nums[++fast]);
            for (; slow <= fast && currSum >= s; currSum -= nums[slow++]);
            if (slow > fast) { return 1; }
            ans = min(ans, fast-slow+2);
        } while (fast < len-1);
        return ans;
    }
};

