/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxend = 0;
        for(int i=0; i<=maxend; i++) {
            if(i+nums[i]>=n-1) return true;
            maxend = max(maxend, i+nums[i]);
        }
        return false;
    }
};

