
/**
 * 11. Container With Most Water
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container and n is at least 2.
 */
 
//先暴力的完成下每天的任务……FPGA太难tm调了……
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