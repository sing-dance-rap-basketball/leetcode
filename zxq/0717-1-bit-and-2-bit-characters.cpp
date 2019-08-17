/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */

/*
    √ Accepted
    √ 93/93 cases passed (0 ms)
    √ Your runtime beats 100 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (8.5 MB)
 */
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.back() == 1) { return false; }
        if (bits.size() == 1) { return true; }
        int count = 0;
        for (int i = bits.size()-2; i >= 0; --i) {
            if (bits[i] == 0) {
                break;
            }
            ++count;
        }
        if (count % 2 == 0) {
            return true;
        }
        return false;
    }
};

