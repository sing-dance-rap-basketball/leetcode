/*
 * @lc app=leetcode id=798 lang=cpp
 *
 * [798] Smallest Rotation with Highest Score
 */

// /*
//     O(n^2) solution:
//     × Time Limit Exceeded
//     × 26/36 cases passed (N/A)
//  */
// class Solution {
// public:
//     int bestRotation(vector<int>& A) {
//         // K = 0
//         int highest_score = 0;
//         int highest_idx = 0;
//         for (int i = 0; i < A.size(); ++i) {
//             A[i] -= i;
//             if (A[i] <= 0) {
//                 ++highest_score;
//             }
//         }
//         // K > 0
//         for (int k = 1; k < A.size(); ++k) {
//             int curr_score = 0;
//             int last_elem = A[0] - (A.size() - 1);
//             for (int i = 0; i < A.size() - 1; ++i) {
//                 A[i] = A[i+1] + 1;
//                 if (A[i] <= 0) {
//                     ++curr_score;
//                 }
//             }
//             A.back() = last_elem;
//             if (last_elem <= 0) {
//                 ++curr_score;
//             }
//             if (curr_score > highest_score) {
//                 highest_score = curr_score;
//                 highest_idx = k;
//             }
//         }
//         return highest_idx;
//     }
// };

// /*
//     × Time Limit Exceeded
//     × 36/36 cases passed (N/A)
//     × testcase: '' (a thousand of 500)
//     × answer: 
//     × expected_answer: 
//     × stdout:
//  */
// class Solution {
// public:
//     int bestRotation(vector<int>& A) {
//         int len = A.size();
//         int *score = new int[len]();
//         for (int i = 0; i < len; ++i) {
//             if (A[i] <= 0) {
//                 for (int j = 0; j < len; ++j) {
//                     ++score[j];
//                 }
//             }
//             else if (A[i] < len) {
//                 if (A[i] <= i) {
//                     for (int j = 0; j <= i - A[i]; ++j) {
//                         ++score[j];
//                     }
//                     for (int j = i + 1; j < len; ++j) {
//                         ++score[j];
//                     }
//                 }
//                 else {
//                     for (int j = i + 1; j <= len - (A[i] - i); ++j) {
//                         ++score[j];
//                     }
//                 }
//             }   
//             else {
//                 continue;
//             }
//         }

//         int highest_score = score[0];
//         int highest_idx = 0;
//         for (int i = 1; i < len; ++i) {
//             if (score[i] > highest_score) {
//                 highest_score = score[i];
//                 highest_idx = i;
//             }
//         }

//         delete[] score;
//         return highest_idx;
//     }
// };

// /*
//     Optimize previous solution:
//     √ Accepted
//     √ 36/36 cases passed (1676 ms)
//     √ Your runtime beats 5.13 % of cpp submissions
//     √ Your memory usage beats 80 % of cpp submissions (10.9 MB)
//  */
// class Solution {
// public:
//     int bestRotation(vector<int>& A) {
//         int len = A.size();
//         int *score = new int[len]();
//         for (int i = 0; i < len; ++i) {
//             if (A[i] <= 0) {
//                 for (int j = 0; j < len; ++j) {
//                     ++score[j];
//                 }
//             }
//             else if (A[i] < len) {
//                 if (A[i] <= i) {
//                     int temp = i - A[i];
//                     for (int j = 0; j <= temp; ++j) {
//                         ++score[j];
//                     }
//                     for (int j = i + 1; j < len; ++j) {
//                         ++score[j];
//                     }
//                 }
//                 else {
//                     int temp = len - (A[i] - i);
//                     for (int j = i + 1; j <= temp; ++j) {
//                         ++score[j];
//                     }
//                 }
//             }   
//             else {
//                 continue;
//             }
//         }

//         int highest_score = score[0];
//         int highest_idx = 0;
//         for (int i = 1; i < len; ++i) {
//             if (score[i] > highest_score) {
//                 highest_score = score[i];
//                 highest_idx = i;
//             }
//         }

//         delete[] score;
//         return highest_idx;
//     }
// };

/* 
    https://leetcode.com/problems/smallest-rotation-with-highest-score/discuss/130531/A-(hopefully)-understandable-explanation-O(n)

    This problem can be thought of as a transformation to a more well known problem. 
    After we have the transformation, we can solve it effiently.

    Definitions
    Let A be the input array, and N be the number of elements in the array. 
    Let A[i] denote the value at index i in input array A. 
    And let K be the number of rotations.

    The Transformation
    For every number in the array, write the ranges which the value will yield a score of + 1.

    Example:
    A: [2, 3, 1, 4, 0]
    Range for 2: [1, 3] (Rotating the array for any value of 1 <= K <= 3 will give us a point for 2.
    Range for 3: [2, 3]
    Range for 1: [0, 1] and [3, 4]
    ... and so on

    After doing that, the value of K that gives the highest score is the value 
    that is common to the most # of ranges. 
    The question is how do we solve for that value? 
    A simple approach would be to keep an array, called count, 
    with indices from 0 to 4, and add 1 to each indice for every range that contains it. 
    At the end the best value of k is the indice for which count has the largest value.

    Example:
    count would look like this if we added + 1 for range [1, 3]: count [0, 1, 1, 1, 0]. 
    We would continue to add for every range. 
    So after adding range [2, 3], count would look like [0, 1, 2, 2, 0] ... and so on.

    But this would be O(n^2). We can improve this by making a simple adaptation. 
    To represent some range [a, b] we can instead add +1 to only the indice a, 
    and subtract 1 to the last b + 1 (if it exists). 
    This would mean that we add +1 to every index >= a, and subtract -1 to every index b + 1. 
    After doing this for every range, we can accumate from the front, 
    we should get the same array count, as we did with out n^2 version.
 */
/*
    √ Accepted
    √ 36/36 cases passed (28 ms)
    √ Your runtime beats 97.39 % of cpp submissions
    √ Your memory usage beats 80 % of cpp submissions (11 MB)
 */
class Solution {
public:
    int bestRotation(vector<int>& A) {
        int len = A.size();
        int *score = new int[len]();
        for (int i = 0; i < len; ++i) {
            if (A[i] <= 0 || A[i] >= len) {
                continue;   // need to do nothing
            }
            else { // 0 < A[i] < len
                if (i >= A[i]) {
                    --score[i-A[i]+1];
                    if (i+1 < len) { ++score[i+1]; }
                }
                else {
                    ++score[i+1];
                    if (i-A[i]+1 < 0) { --score[i-A[i]+1+len]; }
                }
            }
        }

        int highest_idx = 0;
        for (int i = 1; i < len; ++i) {
            score[i] += score[i-1];
            highest_idx = score[i] > score[highest_idx] ? i : highest_idx;
        }

        delete[] score;
        return highest_idx;
    }
};