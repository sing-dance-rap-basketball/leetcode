/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

/*
  √ 172/172 cases passed (4 ms)
  √ Your runtime beats 99.31 % of cpp submissions
  √ Your memory usage beats 43.94 % of cpp submissions (9.4 MB)
  √ 172/172 cases passed (8 ms)
  √ Your runtime beats 88.64 % of cpp submissions
  √ Your memory usage beats 39.93 % of cpp submissions (9.5 MB)
*/
class Solution {
public:
    vector<vector<int>> combinSum2(vector<int>& candi, int front, int back, int target)
    {
        vector<vector<int>> res;
        if (front > back) { return res; }
        // front <= back
        for (int i = front; i <= back; ++i) {
            if (target < candi[i]) { return res; }
            else if (target == candi[i]) {
                res.push_back(vector<int>{target});
                return res;
            }
            else {
                auto tempRes = this->combinSum2(candi, i+1, back, target-candi[i]);
                if (!tempRes.empty()) {
                    for (auto& v : tempRes) {
                        v.push_back(candi[i]);
                    }
                    //res.reserve(res.size() + tempRes.size());
                    res.insert(res.end(), tempRes.begin(), tempRes.end());
                    for (; i+1 <= back && candi[i] == candi[i+1]; ++i);
                }
                for (; i+1 <= back && candi[i] == candi[i+1]; ++i);
            }
        }
        return res;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        return this->combinSum2(candidates, 0, candidates.size()-1, target);
    }
};

