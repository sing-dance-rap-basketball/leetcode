/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start

/**
 * Accepted
    45/45 cases passed (4 ms)
    Your runtime beats 22.91 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.9 MB)
 */
// class Solution {
// public:
//     bool rotateString(string A, string B) {
//         if (A.empty() && B.empty()) return true;
//         for (int i = 0; i < A.size(); ++i) {
//             if (rotateString(A, i) == B) return true;
//         }
//         return false;
//     }

//     string rotateString(string& A, int shift) {
//         // shift >= 0
//         shift %= A.size();
//         string res = A.substr(shift);
//         res += A.substr(0, shift);
//         return res;
//     }
// };

/**
 * Accepted
    45/45 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.1 MB)
 */
class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size()
                && (A + A).find(B) != string::npos;
    }
};
// @lc code=end

