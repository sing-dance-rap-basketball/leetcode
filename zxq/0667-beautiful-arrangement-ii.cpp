/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 */

// /*
//     √ Accepted
//     √ 68/68 cases passed (104 ms)
//     √ Your runtime beats 6.19 % of cpp submissions
//     √ Your memory usage beats 100 % of cpp submissions (9.2 MB)
//  */

// class Solution {
// public:
//     vector<int> constructArray(int n, int k) {
//         vector<int> res(n);
//         for (int i = 0; i < n; ++i) {
//             res[i] = i+1;
//         }
//         --k;
//         while (k > 0) {
//             int lastnum = res.back();
//             int idx = res.size()-1;
//             for(int i = 0; i < k; --idx, ++i) {
//                 res[idx] = res[idx-1];
//             }
//             res[idx] = lastnum;
//             k -= 2;
//         }
//         return res;
//     }
// };

/*
    √ Accepted
    √ 68/68 cases passed (20 ms)
    √ Your runtime beats 96.01 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (9.3 MB)
 */
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res {};
        res.reserve(n);
        int temp_sum = n + (n - k);
        for (int i = 0, count = k/2; i <= count; ++i) {
            res.push_back(n - i);
            res.push_back(temp_sum - (n - i));
        }
        if (k % 2 == 0) {
            res.pop_back();
        }
        for (int num = n-k-1; num > 0; --num) {
            res.push_back(num);
        }
        return res;
    }
};