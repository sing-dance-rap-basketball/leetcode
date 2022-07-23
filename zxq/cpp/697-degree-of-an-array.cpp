/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

/*
    √ Accepted
    √ 89/89 cases passed (36 ms)
    √ Your runtime beats 90.01 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (12.6 MB)
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        std::unordered_map<int, int> um {};
        int max_deg = 0;
        vector<int> max_freq {};
        for (int i = 0; i < nums.size(); ++i) {
            ++um[nums[i]];
            if (um[nums[i]] > max_deg) {
                max_deg = um[nums[i]];
                max_freq.clear();
                max_freq.push_back(nums[i]);
            }
            else if (um[nums[i]] == max_deg) {
                max_freq.push_back(nums[i]);
            }
        }
        if (max_deg == 1) { return 1; }
        int shortest = nums.size();
        for (int n : max_freq) {
            int start = -1;
            int end = nums.size();
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == n) {
                    start = i;
                    break;
                }
            }
            for (int i = nums.size()-1; i >= 0; --i) {
                if (nums[i] == n) {
                    end = i;
                    break;
                }
            }
            shortest = std::min(shortest, end-start+1);
        }
        return shortest;
    }
};

