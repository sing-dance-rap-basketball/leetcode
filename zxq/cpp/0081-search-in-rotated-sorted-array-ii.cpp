/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

/*
    √ Accepted
    √ 275/275 cases passed (4 ms)
    √ Your runtime beats 99.09 % of cpp submissions
    √ Your memory usage beats 44.4 % of cpp submissions (8.8 MB)
    √ Accepted
    √ 275/275 cases passed (8 ms)
    √ Your runtime beats 71.5 % of cpp submissions
    √ Your memory usage beats 95.68 % of cpp submissions (8.6 MB)
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) { return false; }
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) {
                return true;
            }
            else if (target < nums[mid]) {
                if (nums[mid] < nums[right]) {
                    right = mid - 1;
                }
                else if (nums[mid] > nums[right]) {
                    if (target > nums[left]) {
                        right = mid - 1;
                    }
                    else if (target == nums[left]) {
                        return true;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                else {
                    int i;
                    for (i = mid; i < right; ++i) {
                        if (nums[i] != nums[mid]) { break; }
                    }
                    if (i < right) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
            }
            else {  // target > nums[mid]
                if (nums[mid] > nums[left]) {
                    left = mid + 1;
                }
                else if (nums[mid] < nums[left]) {
                    if (target == nums[right]) {
                        return true;
                    }
                    else if (target > nums[right]) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                else {
                    int i;
                    for (i = left; i < mid; ++i) {
                        if (nums[i] != nums[mid]) { break; }
                    }
                    if (i < mid) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};

// /*
//     Other's solution
//  */
// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1;
//         while (l <= r) {
//             while (l < r && nums[l] == nums[l + 1]) {
//                 l++;
//             }
//             while (l < r && nums[r] == nums[r - 1]) {
//                 r--;
//             }
//             int m = l + (r - l) / 2;
//             if (nums[m] == target) {
//                 return true;
//             }
//             if (nums[m] > target) {
//                 if (nums[l] > nums[m] || nums[l] <= target) {
//                     r = m - 1;
//                 } else {
//                     l = m + 1;
//                 }
//             } else {
//                 if (nums[l] <= nums[m] || nums[l] > target) {
//                     l = m + 1;
//                 } else {
//                     r = m - 1;
//                 }
//             }
//         }
//         return false;
//     }
// };

// /*
//     Other's solution
//  */
// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int left = 0, right =  nums.size()-1, mid;
        
//         while(left<=right)
//         {
//             mid = (left + right) >> 1;
//             if(nums[mid] == target) return true;

//             // the only difference from the first one, trickly case, just updat left and right
//             if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}

//             else if(nums[left] <= nums[mid])
//             {
//                 if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
//                 else left = mid + 1; 
//             }
//             else
//             {
//                 if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
//                 else right = mid-1;
//             }
//         }
//         return false;
//     }
// };