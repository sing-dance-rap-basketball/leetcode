/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */
// class Solution {
// public:
//     int numTilings(int N) {
//         switch (N)
//         {
//         case 1:
//             return 1;
//             break;
//         case 2: 
//             return 2;
//             break;
//         case 3:
//             return 5;
//             break;
//         case 4:
//             return 11;
//             break;
//         case 5:
//             return 24;
//             break;
//         case 6:
//             return 53;
//             break;
//         case 7:
//             return 117;
//             break;
//         case 8:
//             return 258;
//             break;
//         default:
//             return -1;
//             break;
//         }
//     }
// };

/*
    √ Accepted
    √ 39/39 cases passed (4 ms)
    √ Your runtime beats 66.25 % of cpp submissions
    √ Your memory usage beats 75 % of cpp submissions (8.6 MB)
 */
class Solution {
public:
    vector<int> res {1, 2, 5};
    int numTilings(int N) {
        if (N <= res.size()) {
            return res[N-1];
        }
        for (int i = 3; i < N; ++i) {
            res.push_back((res[i-1] * 2 % 1000000007+ res[i-3]) % 1000000007);
        }
        return res.back();
    }
};