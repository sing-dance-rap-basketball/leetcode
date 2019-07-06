
/**
 * 11. Container With Most Water
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container and n is at least 2.
 */
 
/**
 * 先暴力的完成下每天的任务……FPGA太难tm调了……
 * 1388ms 9.9MB
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int maxVolume = 0;
        for (int i = 0; i < length; ++i) {
            for (int j = i; j < length; ++j) {
                int h = (height[i] > height[j])?height[j]:height[i];
                int tmpVolume = h * (j - i);
                if (tmpVolume > maxVolume)
                    maxVolume = tmpVolume;
            }
        }
        return maxVolume;
    }
};

/**
 * 双指针的方法
 * 1.短板决定天花板
 * 2.从最长底边开始 左移右移底都会短 判断条件便简化到高度上
 * 引用两个不错的解释
 * https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
 * https://leetcode.com/problems/container-with-most-water/discuss/6100/Simple-and-clear-proofexplanation
 * 16ms 9.9MB
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxVolume = 0;
        while (left <= right) {
            int volume = std::min(height[left],height[right]) * (right - left);
            if (volume > maxVolume) {
                maxVolume = volume;
            }

            if(height[left] > height[right])
                --right;
            else
                ++left;
        }
        return maxVolume;
    }
};

