/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1, vector<vector<int>>());
        dp[0].push_back(vector<int>());
        for(int i : candidates) {
            for(int j = i; j<=target; j++) {
                if(dp[j-i].size()>0){
                    auto tmp = dp[j-i];
                    for(auto &k : tmp)
                        k.push_back(i);
                    dp[j].insert(dp[j].end(), tmp.begin(), tmp.end());
                }
            }
        }
        return dp[target];
    }
};

