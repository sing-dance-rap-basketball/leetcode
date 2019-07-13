/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        DFS(0, nums, results);
        return results;
    }

    void DFS(int pos, vector<int> nums, vector<vector<int>>& results) {
        if(nums.size()-1 == pos) {
            results.push_back(nums);
            return;
        }
        for(int i = pos; i<nums.size(); i++) {
            if(i != pos && nums[i] == nums[pos]) continue;
            swap(nums[i], nums[pos]);
            DFS(pos+1, nums, results);
        }
        return;
    }
};

