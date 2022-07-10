/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// /*
//   √ 168/168 cases passed (64 ms)
//   √ Your runtime beats 16.01 % of cpp submissions
//   √ Your memory usage beats 13.76 % of cpp submissions (21.5 MB)
//   √ 168/168 cases passed (60 ms)
//   √ Your runtime beats 17.17 % of cpp submissions
//   √ Your memory usage beats 13.76 % of cpp submissions (21.4 MB)
// */
// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         int len = candidates.size();
//         vector<vector<int>> res;
//         if (len == 0) { return res; }
//         if (len == 1) {
//             if (target % candidates[0] == 0) {
//                 res.push_back(vector<int>(target / candidates[0], candidates[0]));
//                 return res;
//             }
//             else {
//                 return res;
//             }
//         }
//         // len >= 2
//         //for (int i = 0; i <= target / candidates[0]; ++i) {
//         for (int i = target / candidates[0]; i >= 0; --i) {
//             int remainder = target - candidates[0] * i;
//             if (remainder != 0) {
//                 vector<int> tempCandi (candidates.begin()+1, candidates.end());
//                 auto tempRes = combinationSum(tempCandi, remainder);
//                 int tempLen = tempRes.size();
//                 if (tempLen > 0) {
//                     for (int j = 0; j < i; ++j) {
//                         for (auto& v : tempRes) {
//                             v.push_back(candidates[0]);
//                         }
//                     }
//                     res.reserve(res.size() + tempLen);
//                     res.insert(res.end(), tempRes.begin(), tempRes.end());
//                 }
//             }
//             else {  // remainder == 0
//                 res.push_back(vector<int>(i, candidates[0]));
//             }
//         }
//         return res;
//     }
// };

/*
  √ 168/168 cases passed (12 ms)
  √ Your runtime beats 86.67 % of cpp submissions
  √ Your memory usage beats 46.24 % of cpp submissions (11 MB)
  √ 168/168 cases passed (16 ms)
  √ Your runtime beats 59.5 % of cpp submissions
  √ Your memory usage beats 46.29 % of cpp submissions (10.9 MB)
*/
class Solution {
public:
    vector<vector<int>> combiSum(vector<int>& candi, int front, int back, int target)
    {
        vector<vector<int>> res;
        if (front > back) { return res; }
        for (int i = back; i >= front; --i) {
            if (target < candi[i]) { 
                return combiSum(candi, front, i-1, target); 
            }
            for (int j = target / candi[i]; j > 0; --j) {
                if (target - j * candi[i] == 0) {
                    res.push_back(vector<int>(j, candi[i]));
                    continue;
                }
                auto tempRes = this->combiSum(candi, front, i-1, target-j*candi[i]);
                if (!tempRes.empty()) {
                    for (int k = 0; k < j; ++k) {
                        for (auto& v : tempRes) {
                            v.push_back(candi[i]);
                        }
                    }
                    res.insert(res.end(), tempRes.begin(), tempRes.end());
                }
            }
        }
        return res;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        return this->combiSum(candidates, 0, candidates.size()-1, target);
    }
};
