/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// /*
//     √ Accepted
//     √ 10/10 cases passed (4 ms)
//     √ Your runtime beats 98.3 % of cpp submissions
//     √ Your memory usage beats 61.29 % of cpp submissions (9.1 MB)
//  */
// class Solution {
// public:
//     void int2array(int tickNum, vector<bool>& tick)
//     {
//         for (int i = tick.size() - 1; i >= 0; --i) {
//             tick[i] = false;
//         }

//         int digitPos = 0;
//         while (tickNum != 0) {
//             if (tickNum & 1) {
//                 tick[digitPos] = true;
//             }
//             ++digitPos;
//             tickNum = tickNum >> 1;
//         }

//         return;
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> res;
//         if (nums.empty()) { return res; }
        
//         vector<bool> tick(nums.size(), false);
//         int sup = pow(2, nums.size()-1);
//         for (int i = 0; i < sup; ++i) {
//             int2array(i, tick);
//             vector<int> tempArray1, tempArray2;
//             for (int j = 0; j < tick.size(); ++j) {
//                 if (tick[j]) {
//                     tempArray1.push_back(nums[j]);
//                 }
//                 else {
//                     tempArray2.push_back(nums[j]);
//                 }
//             }
//             res.push_back(tempArray1);
//             res.push_back(tempArray2);
//         }

//         return res;
//     }
// };

/*
    Backtrack: 
    √ Accepted
    √ 10/10 cases passed (8 ms)
    √ Your runtime beats 65.28 % of cpp submissions
    √ Your memory usage beats 68.58 % of cpp submissions (9.1 MB)
    √ Accepted
    √ 10/10 cases passed (4 ms)
    √ Your runtime beats 98.21 % of cpp submissions
    √ Your memory usage beats 83.44 % of cpp submissions (9 MB)
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res {};
        vector<int> sub {};
        Backtrack(nums, res, sub, 0);
        return res;
    }

    void Backtrack(const vector<int>& nums, vector<vector<int>>& res, 
                vector<int>& sub, int idx) {
        res.push_back(sub);
        for (int i = idx; i < nums.size(); ++i) {
            sub.push_back(nums[i]);
            Backtrack(nums, res, sub, i+1);
            sub.pop_back();
        }
        return;
    }
};