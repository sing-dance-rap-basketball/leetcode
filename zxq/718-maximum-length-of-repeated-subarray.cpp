/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// /*
//     × Time Limit Exceeded
//     × 38/54 cases passed (N/A)
//  */
// class Solution {
// public:
//     int findLength(vector<int>& A, vector<int>& B) {
//         int res = 0;
//         for (int i = 0; i < A.size(); ++i) {
//             for (int j = 0; j < B.size(); ++j) {
//                 if (A[i] == B[j]) {
//                     res = std::max(res, compare(A, i, B, j));
//                 }
//             }
//         }
//         return res;
//     }
// private:
//     int compare(vector<int>& A, int startA, vector<int>& B, int startB)
//     {
//         int sameLen = 0;
//         for (int i = 0; i+startA < A.size() && i+startB < B.size(); ++i) {
//             if (A[startA+i] == B[startB+i]) {
//                 ++sameLen;
//             }
//             else {
//                 break;
//             }
//         }
//         return sameLen;
//     }
// };

/*


 */
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {

    }
};
