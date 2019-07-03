/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        auto l = std::begin(height);
        auto r = std::end(height);
        r--;
        int ans = 0; 
        int l_max = 0, r_max = 0;
        while (l < r) {
            if((*l) < (*r)) {
                ((*l) >= l_max) ? (l_max = (*l)) : ans += (l_max - (*l));
                l++;
            } else {
                ((*r) >= r_max) ? (r_max = (*r)) : ans += (r_max - (*r));
                r--;
            }
        }
        return ans;
    }
};

