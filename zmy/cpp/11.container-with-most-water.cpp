/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// 妈的还以为要减去黑色的条....
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0; int right = len - 1;
        int maxArea = INT_MIN; //int cur_hei_max = INT_MIN;
        while (left < right) {
            int h = min(height[left], height[right]);
            maxArea = max(maxArea, h*(right - left));
            while(height[left]<=h && left<right) left++;
            while(height[right]<=h && left<right) right--;
            // if(min(height[left], height[right]) > cur_hei_max) {
            //     cur_hei_max = min(height[left], height[right]);
            // } else {
            //     if(height[left] < height[right]) {
            //         left ++;
            //     } else {
            //         right --;
            //     }
            //     continue;
            // }
            
            // int temp = cur_hei_max * (right - left);
            // if (temp > maxArea) {
            //     maxArea = temp;
            // }
        }
        return maxArea;
    }
};

