/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

/*
    √ Accepted
    √ 66/66 cases passed (12 ms)
    √ Your runtime beats 92.21 % of cpp submissions
    √ Your memory usage beats 94.62 % of cpp submissions (10.5 MB)
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int majority1, majority2;
        for (int n : nums) {
            if (count1 > 0 & count2 > 0) {
                if (majority1 == n) { ++count1; }
                else if (majority2 == n) { ++count2; }
                else { --count1; --count2; }
            }
            else if (count1 == 0 && count2 == 0) {
                majority1 = n;
                ++count1;
            }
            else if (count1 > 0 && count2 == 0) {
                if (majority1 == n) { ++count1; }
                else {
                    majority2 = n;
                    ++count2;
                }
            }
            else {  // count1 == 0 && count2 > 0
                if (majority2 == n) { ++count2; }
                else {
                    majority1 = n;
                    ++count1;
                }
            }
        }

        bool is1 = (count1 > 0);
        bool is2 = (count2 > 0);
        count1 = 0; 
        count2 = 0;
        for (int n : nums) {
            if (n == majority1) { ++count1; }
            if (n == majority2) { ++count2; }
        }
        is1 = is1 && (count1 > nums.size() / 3);
        is2 = is2 && (count2 > nums.size() / 3);
        if (is1 && is2) {
            return vector<int> {majority1, majority2};
        }
        else if (is1 && !is2) {
            return vector<int> {majority1};
        }
        else if (!is1 && is2) {
            return vector<int> {majority2};
        }
        return vector<int> {};
    }   
};

