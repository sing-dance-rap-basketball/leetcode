/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// /*
//     × Time Limit Exceeded
//     × 41/41 cases passed (N/A)
//     × testcase: '[2433,3054,9952, ... ,211,-9583]\n10000\n0'
//     × answer: 
//     × expected_answer: 
//     × stdout:
//  */
// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//         int len = nums.size()-1;
//         for (int i = 0; i < len; ++i) {
//             for (int j = k > len - i ? len : k+i; j > i; --j) {
//                 if (abs((long)nums[j]-(long)nums[i]) <= t) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

/*
√ Accepted
  √ 41/41 cases passed (20 ms)
  √ Your runtime beats 61.46 % of cpp submissions
  √ Your memory usage beats 83.05 % of cpp submissions (10.8 MB)
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 0 || t < 0) { return false; }
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = m.find(nums[i]);
            if (it == m.end()) {
                m[nums[i]] = i;
                it = m.find(nums[i]);
            }
            else {
                if (i - it->second <= k) { return true; }
                it->second = i;
            }
            for (auto it_l = it; it_l-- != m.begin();) {
                if ((long)it->first - (long)it_l->first > t) { break; }
                if (i - it_l->second <= k) { return true; }
            }
            for (auto it_r = it; ++it_r != m.end();) {
                if ((long)it_r->first - (long)it->first > t) { break; }
                if (i - it_r->second <= k) { return true; }
            }
        }
        return false;
    }
};