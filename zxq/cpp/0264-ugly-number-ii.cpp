/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start

/**
 * Time Limit Exceeded
    325/596 cases passed (N/A)
    Testcase
    326
 */
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         unordered_map<int, int> umap {{1, 1}};
//         int count = 0;
//         int ans = 1;
//         for (int i = 1; i <= INT_MAX; ++i) {
//             if (umap[i] == 1) {
//                 if (++count == n) {
//                     ans = i;
//                     break;
//                 }
//                 umap[i*2] = 1;
//                 umap[i*3] = 1;
//                 umap[i*5] = 1;
//             }
//         }

//         return ans;
//     }
// };

/**
 * Time Limit Exceeded
    453/596 cases passed (N/A)
    Testcase
    454
 */
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         unordered_map<int, int> umap {{1, 1}};
//         int count = 1;
//         int ans = 1;
//         for (int i = 2; count < n; ++i) {
//             if (i % 2 == 0) {
//                 if (umap.find(i / 2) != umap.end()) {
//                     umap[i] = 1;
//                     ++count;
//                     ans = i;
//                 }
//             }
//             else if (i % 3 == 0) {
//                 if (umap.find(i / 3) != umap.end()) {
//                     umap[i] = 1;
//                     ++count;
//                     ans = i;
//                 }
//             }
//             else if (i % 5 == 0) {
//                 if (umap.find(i / 5) != umap.end()) {
//                     umap[i] = 1;
//                     ++count;
//                     ans = i;
//                 }
//             }
//         }

//         return ans;
//     }
// };

/**
 * Accepted
    596/596 cases passed (12 ms)
    Your runtime beats 51.15 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (7.7 MB)
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) exit(1); 
        int t2 = 0, t3 = 0, t5 = 0; 
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2, min(k[t3]*3, k[t5]*5));
            if(k[i] == k[t2]*2) ++t2; 
            if(k[i] == k[t3]*3) ++t3;
            if(k[i] == k[t5]*5) ++t5;
        }
        return k.back();
    }
};
// @lc code=end

