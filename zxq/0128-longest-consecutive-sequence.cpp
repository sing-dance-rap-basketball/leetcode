/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

/*
    √ Accepted
    √ 68/68 cases passed (12 ms)
    √ Your runtime beats 69.99 % of cpp submissions
    √ Your memory usage beats 5.77 % of cpp submissions (10.8 MB)
 */
class Union_Find{
public:
    Union_Find (int N) {
        for (int i = 0; i < N; i++) {
            id.push_back(i);
            sz.push_back(1);
        }
    }

    void Union(int A, int B) {
        int rootA = Find(A);
        int rootB = Find(B);
        if (rootA == rootB) return;
        if (sz[rootA] < sz[rootB]) {
            id[rootA] = rootB;
            sz[rootB] += sz[rootA];
        } else {
            id[rootB] = rootA;
            sz[rootA] += sz[rootB];
        }
    }

    int Find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    int maxSize() {
        int res = 0;
        for (auto s : sz)
            res = max(res, s);
        return res;
    }
    
private:
    vector<int> id;
    vector<int> sz;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        Union_Find uf(nums.size());
        unordered_map<int, int> mapIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (mapIndex.count(nums[i])) continue; // in case of duplicate
            mapIndex.insert(make_pair(nums[i], i));
            
            if (mapIndex.count(nums[i] + 1)) {
                uf.Union(i, mapIndex[nums[i] + 1]);
            }
            if (mapIndex.count(nums[i] - 1)) {
                uf.Union(i, mapIndex[nums[i] - 1]);
            }
        }
        return uf.maxSize();
    }
};

// /*
//     sort first
//     √ Accepted
//     √ 68/68 cases passed (8 ms)
//     √ Your runtime beats 95.36 % of cpp submissions
//     √ Your memory usage beats 98.08 % of cpp submissions (9.2 MB)
//  */
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if (nums.empty()) { return 0; }
//         sort(nums.begin(), nums.end());
//         int ans = 1;
//         int seqLen = 1;
//         for (int i = 0; i < nums.size(); ++i) {
//             for (; i+1 < nums.size() && nums[i] == nums[i+1]; ++i);
//             if (i == nums.size()-1) { break; }

//             if (nums[i] + 1 == nums[i+1]) {
//                 ++seqLen;
//             }
//             else {
//                 seqLen = 1;
//             }
//             ans = max(ans, seqLen);
//         }
//         return ans;
//     }
// };

// /*
//     HashSet and Intelligent Sequence Building
//     √ Accepted
//     √ 68/68 cases passed (12 ms)
//     √ Your runtime beats 69.99 % of cpp submissions
//     √ Your memory usage beats 82.69 % of cpp submissions (10 MB)
//  */
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> us(nums.begin(), nums.end());
        
//         int longestStreak = 0;
//         for (auto num : us) {
//             // num must be the smallest of a sequence
//             if (us.find(num-1) != us.end()) { continue; }
//             int currNum = num;
//             int currStreak = 1;
//             while (us.find(currNum+1) != us.end()) {
//                 ++currNum;
//                 ++currStreak;
//             }
//             longestStreak = max(longestStreak, currStreak);
//         }
//         return longestStreak;
//     }
// };
