/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

/*
    √ Accepted
    √ 83/83 cases passed (48 ms)
    √ Your runtime beats 81.4 % of cpp submissions
    √ Your memory usage beats 73.33 % of cpp submissions (11 MB)
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max_1 = INT_MIN, max_2 = INT_MIN, max_3 = INT_MIN;
        int min_1 = INT_MAX, min_2 = INT_MAX; // min_3 = INT_MAX;
        for (auto n : nums) {
            if (n >= max_1) {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = n;
            }
            else if (n >= max_2) {
                max_3 = max_2;
                max_2 = n;
            }
            else if (n >= max_3) {
                max_3 = n;
            }
            
            if (n <= min_1) {
                // min_3 = min_2;
                min_2 = min_1;
                min_1 = n;
            }
            else if (n <= min_2) {
                // min_3 = min_2;
                min_2 = n;
            }
            // else if (n <= min_3) {
            //     min_3 = n;
            // }
        }
        return std::max(max_1 * max_2 * max_3, max_1 * min_1 * min_2);
    }
};

