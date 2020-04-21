/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * [888] Fair Candy Swap

    Alice and Bob have candy bars of different sizes: 
    A[i] is the size of the i-th bar of candy that Alice has, 
    and B[j] is the size of the j-th bar of candy that Bob has.

    Since they are friends, they would like to exchange one candy bar 
    each so that after the exchange, they both have the same total amount of candy.  
    (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

    Return an integer array ans where ans[0] is the size of the candy bar 
    that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.

    If there are multiple answers, you may return any one of them.  
    It is guaranteed an answer exists.

 */

// @lc code=start

/**
 * Time Limit Exceeded
 * 75 / 75 test cases passed, but took too long.
 */
// class Solution {
// public:
//     vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
//         int sumA = 0, sumB = 0;
//         for (int Ai : A) { sumA += Ai; }
//         for (int Bj : B) { sumB += Bj; }

//         int offset = (sumB - sumA) / 2;
//         vector<int> ans;
//         for (int Ai : A) {
//             if (isFound(Ai + offset, B)) {
//                 ans.push_back(Ai);
//                 ans.push_back(Ai + offset);
//                 break;
//             }
//         }
//         return ans;
//     }

//     bool isFound(int num, vector<int>& v) {
//         for (int vi : v) {
//             if (vi == num) return true;
//         }
//         return false;
//     }
// };

/**
 * Accepted
    75/75 cases passed (156 ms)
    Your runtime beats 45.76 % of cpp submissions
    Your memory usage beats 10 % of cpp submissions (22.2 MB)
 */
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0, sumB = 0;
        for (int Ai : A) { sumA += Ai; }
        for (int Bj : B) { sumB += Bj; }

        int offset = (sumB - sumA) / 2;
        unordered_map<int, int> umap;
        vector<int> ans;
        for (int Ai : A) {
            ++umap[Ai + offset];
        }
        for (int Bj : B) {
            if (umap.find(Bj) != umap.end()) {
                ans.push_back(Bj - offset);
                ans.push_back(Bj);
                break;
            }
        }
        return ans;
    }
};

// @lc code=end

