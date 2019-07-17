/**
 * 39. Combination Sum
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * The same repeated number may be chosen from candidates unlimited number of times.
 * Note:
 *    All numbers (including target) will be positive integers.
 *    The solution set must not contain duplicate combinations.
 */

/**
 * Runtime: 16 ms, faster than 59.50% of C++ online submissions for Combination Sum.
 * Memory Usage: 10.8 MB, less than 48.91% of C++ online submissions for Combination Sum.
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target, res, tmp);
        return res;
    }
    
    void dfs(vector<int> &candidates, int start, int value, int target,
                                            vector<vector<int>> &res, vector<int> tmp) 
    {
        if (value == target) {
            res.push_back(tmp);
            return ;
        }
        else {
            for (int i = start; i < candidates.size(); ++i) {
                if (value + candidates[i] > target)
                    return;
                else {
                    tmp.push_back(candidates[i]);
                    dfs(candidates, i, value + candidates[i], target, res, tmp);
                    tmp.pop_back();
                }
            }
        }
        return ;
    }
};
