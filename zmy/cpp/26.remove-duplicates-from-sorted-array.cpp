/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
public:
    
    int removeDuplicates(vector<int>& nums) {
        int index;
        // int n = nums.size();
        index = !nums.empty();
        for(int i:nums) {
            if(i != nums[index - 1])
                nums[index++] = i;
        }
        // for(int i=0; i < n; i++) {
        //     while(i+1 < n && nums[i] == nums[i+1]) {
        //         i++;
        //     }
        //     nums[index++] = nums[i];
        // }
        return index;
    }
};

