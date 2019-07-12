/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
private:
    void f(vector<int> &t, int target, vector<vector<int>> & res, vector<int> r, int i) {
        if(!target) { // target
            res.push_back(r);
            return ;
        }

        while(i<t.size() && target - t[i]>=0) { // rec
            r.push_back(t[i]);
            f(t, target-t[i], res, r, i+1);
            i++;
            while(i<t.size() &&  t[i]==r.back()) i++; // no repeat
            r.pop_back(); // remove last
        }
    } 
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> r;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        f(candidates, target, res, r, 0);
        return res;
    }
};

