/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 */

// /*
//     × Time Limit Exceeded
//  */
// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& A) {
//         unordered_map<int, int> umap;
//         for (int i = 0; i < A.size(); ++i) {
//             int temp = A[i];
//             ++umap[temp];
//             for (int j = i+1; j < A.size(); ++j) {
//                 temp |= A[j];
//                 ++umap[temp];
//             }
//         }
//         return (int)umap.size();
//     }
// };

// /*
//     × Time Limit Exceeded
//     × 75/83 cases passed (N/A)
//  */
// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& A) {
//         unordered_map<int, int> umap;
//         vector<int> f(A.size());    // frontier
//         for (int i = 0; i < A.size(); ++i) {
//             for (int j = 0; j < i; ++j) {
//                 f[j] |= A[i];
//                 ++umap[f[j]];
//             }
//             f[i] = A[i];
//             ++umap[f[i]];
//         }
//         return (int)umap.size(); 
//
//         // unordered_set<int> s;
//         // vector<int> f(A.size());    // frontier
//         // for (int i = 0; i < A.size(); ++i) {
//         //     for (int j = 0; j < i; ++j) {
//         //         f[j] |= A[i];
//         //         s.insert(f[j]);
//         //     }
//         //     f[i] = A[i];
//         //     s.insert(f[i]);
//         // }
//         // return (int)s.size(); 
//     }
// };

/*
    frontier set
 */
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, curr;
        for (int i : A) {
            unordered_set<int> next;
            next.insert(i);
            for (int j : curr) { next.insert(j | i); }
            curr = next;
            for (int j : curr) { res.insert(j); }
        }
        return (int)res.size();
    }
};

// /*
//     https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss/165859/C%2B%2B-O(kN)-solution
//  */
// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& A) {
//         unordered_set<int> s;
//         set<int> t;
//         for (int i : A) {
//             set<int> r;
//             r.insert(i);
//             for (int j : t) r.insert(i | j);
//             t = r;
//             for (int j : t) s.insert(j);
//         }
//         return s.size();
//     }
// };
