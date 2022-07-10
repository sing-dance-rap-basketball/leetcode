/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

/*
    √ Accepted
    √ 42/42 cases passed (20 ms)
    √ Your runtime beats 36.73 % of cpp submissions
    √ Your memory usage beats 92.86 % of cpp submissions (8.4 MB)
 */
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) { return false; }
        unordered_set<int> fail {};
        for (int i = 0; i < nums.size(); ++i) {
            if (fail.find(i) != fail.end()) { continue; }
            int curr = i;
            for (int j = 0; j < len - fail.size(); ++j) {
                int next = (curr + nums[curr]) % len;
                next = next < 0 ? next + len : next;
                if ((nums[curr] > 0) != (nums[next] > 0)) {
                    fail.insert(curr);
                    break;
                }
                if (curr == next) {
                    fail.insert(curr);
                    break;
                }
                if (next == i) {
                    return true;
                }
                curr = next;
            }
        }
        return false;
    }
};

