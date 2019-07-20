/**
 * 46. Permutations
 * Given a collection of distinct integers, return all possible permutations.
 */

/**
 * Runtime: 12 ms, faster than 74.97% of C++ online submissions for Permutations.
 * Memory Usage: 9.2 MB, less than 75.56% of C++ online submissions for Permutations.
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        recurPermute(ret, nums, 0);
        return ret;
    }
private:
    void recurPermute(vector<vector<int>>& ret, vector<int>& nums, int n){
        if (nums.size() == n)
            ret.push_back(nums);
        else {
            for (int i = n; i < nums.size(); ++i) {
                swap(nums[n],nums[i]);
                recurPermute(ret, nums, n + 1);
                swap(nums[n],nums[i]);
            }
        }
    }
};
