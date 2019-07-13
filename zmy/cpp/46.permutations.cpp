/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            swap(nums[i], nums[pos]);
            DFS(pos+1, nums, results);
        }
        return;
    }
};

