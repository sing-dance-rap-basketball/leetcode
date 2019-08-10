/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

/*
    √ Accepted
    √ 123/123 cases passed (20 ms)
    √ Your runtime beats 44.83 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (10.1 MB)
    √ Accepted
    √ 123/123 cases passed (16 ms)
    √ Your runtime beats 84.37 % of cpp submissions
    √ Your memory usage beats 80 % of cpp submissions (10.3 MB)
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l, r = -1;
        int can_planted = 0;
        int len = flowerbed.size();
        for (int i = 0; i < len; ++i) {
            if (flowerbed[i] == 1) {
                r = i;
                break;
            }
        }

        if (r == -1) {
            return ((len + 1) / 2) >= n;
        }
        else {
            can_planted += r / 2;
        }
        
        for (int i = r; i < len; ++i) {
            if (flowerbed[i] == 1) {
                for (; i+1 < len && flowerbed[i+1] == 1; ++i);
                l = i;
            }
            else {
                for (; i+1 < len && flowerbed[i+1] == 0; ++i);
                r = i + 1;
                if (r < len) {
                    if (r - l >= 4) {
                        can_planted += (r - l - 2) / 2;
                    }
                }
                else {
                    can_planted += (r - l - 1) / 2;
                }
            }
        }
        return can_planted >= n;
    }
};

