/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

/*
    √ Accepted
    √ 34/34 cases passed (116 ms)
    √ Your runtime beats 67.76 % of cpp submissions
    √ Your memory usage beats 87.07 % of cpp submissions (14.9 MB)
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res {};
        for (auto k : nums) {
            k = abs(k);
            nums[k-1] = nums[k-1] < 0 ? nums[k-1] : -nums[k-1];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};

