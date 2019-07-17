/**
 * 40. Combination Sum II
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * Each number in candidates may only be used once in the combination.
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 */

/**
 * Runtime: 4 ms, faster than 99.31% of C++ online submissions for Combination Sum II.
 * Memory Usage: 9.4 MB, less than 45.31% of C++ online submissions for Combination Sum II.
 *
 * check for the duplicated element from #39
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target, res, tmp);
        return res;
    }
    
    void dfs(vector<int> &candidates, int start, int value, int target,
                                    vector<vector<int>> &res, vector<int> tmp) 
    {

        int size = candidates.size();
        if (value == target) {
            res.push_back(tmp);
            return ;
        }
        else {
            for (int i = start; i < size; ++i) {
                if (value == 0 && i > 0 && candidates[i] == candidates[i-1])
                    continue;
                
                if (value + candidates[i] > target)
                    return;
                else {
                    tmp.push_back(candidates[i]);
                    dfs(candidates, i + 1, value + candidates[i], target, res, tmp);
                    tmp.pop_back();
                }
                
                while(i + 1 < size && candidates[i] == candidates[i+1])
                    ++i;
                    
            }
        }
        return ;
    }
};
