/**
 * 42. Trapping Rain Water
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 */

/**
 * Runtime: 172 ms, faster than 5.14% of C++ online submissions for Trapping Rain Water.
 * Memory Usage: 9 MB, less than 87.78% of C++ online submissions for Trapping Rain Water.
 * 
 * access same element too much times, time complexity could be improved by reduce this
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int sum = 0;
        for (int i  = 0; i < size; ++i) {
            int l = i;
            int r = i;
            int h = 0;
            int maxL = height[i], maxR = height[i];
            while (l >= 0) {
                if (height[l] > maxL) {
                    maxL = height[l];
                }
                --l;
            }
            while (r < size) {
                if (height[r] > maxR) {
                    maxR = height[r];
                }
                ++r;
            }
            h = maxR < maxL ? maxR : maxL;
            if (i == 0 && i == size - 1)     h = (i == 0)? height[0]:height[size-1];

            sum += h - height[i];
        }
        return sum;
    }
};
