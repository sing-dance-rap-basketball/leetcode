/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

/* 
    √ Accepted
    √ 51/51 cases passed (32 ms)
    √ Your runtime beats 95.58 % of cpp submissions
    √ Your memory usage beats 81.25 % of cpp submissions (10.4 MB)
 */
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) { return false; }
        int i;
        for (i = 1; i < A.size(); ++i) {
            if (A[i] > A[i-1]) {
                continue;
            }
            else if (A[i] == A[i-1]) {
                return false;
            }
            else { // A[i] < A[i-1]
                break;
            }
        }
        if (i == 1 || i == A.size()) { return false; }
        for (i += 1; i < A.size(); ++i) {
            if (A[i] < A[i-1]) {
                continue;
            }
            else {
                return false;
            }
        }
        return i == A.size();
    }
};

