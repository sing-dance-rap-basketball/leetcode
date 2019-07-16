/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

/*
  √ 196/196 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 29.72 % of cpp submissions (8.8 MB)
  √ 196/196 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 5.22 % of cpp submissions (9 MB)
*/
class Solution {
public:
    int BinarySearchRotated(vector<int>& nums, int target, int front, int back)
    {
        if (front > back) {
            return -1;
        }
        else if (front == back) {
            return nums[front] == target ? front : -1;
        }
        else if (front+1 == back) {
            if (nums[front] == target) { return front; }
            else if (nums[back] == target) { return back; }
            else { return -1; }
        }

        int middle = (front + back) / 2;
        if (target == nums[middle]) {
            return middle;
        }
        else if (target < nums[middle]) {
            if (target == nums[front]) {
                return front;
            }
            else if (target > nums[front]) {
                // actually, binary search
                return BinarySearchRotated(nums, target, front+1, middle-1);
            }
            else {  // target < nums[front]
                if (nums[middle] <= nums[back]) {
                    return BinarySearchRotated(nums, target, front+1, middle-1);
                }
                else {
                    return BinarySearchRotated(nums, target, middle+1, back);
                }
            }
        }
        else {  // target > nums[middle]
            if (target == nums[back]) {
                return back;
            }
            else if (target < nums[back]) {
                return BinarySearchRotated(nums, target, middle+1, back-1);
            }
            else {
                if (nums[middle] >= nums[front]) {
                    return BinarySearchRotated(nums, target, middle+1, back-1);
                }
                else {
                    return BinarySearchRotated(nums, target, front, middle-1);
                }
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return BinarySearchRotated(nums, target, 0, nums.size()-1);
    }
};

