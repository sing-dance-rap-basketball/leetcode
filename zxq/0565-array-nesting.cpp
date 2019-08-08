/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */
// /*
//     √ Accepted
//     √ 856/856 cases passed (40 ms)
//     √ Your runtime beats 19.79 % of cpp submissions
//     √ Your memory usage beats 9.09 % of cpp submissions (14.5 MB)
//     √ Accepted
//     √ 856/856 cases passed (36 ms)
//     √ Your runtime beats 23.96 % of cpp submissions
//     √ Your memory usage beats 9.09 % of cpp submissions (14.5 MB)
//  */
// class Solution {
// public:
//     int arrayNesting(vector<int>& nums) {
//         int res = 0;
//         int curr, next;
//         std::unordered_set<int> us;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (us.find(i) != us.end()) { continue; }
//             int count = 0;
//             curr = i;
//             us.insert(curr);
//             ++count;
//             next = nums[curr];
//             while (us.find(next) == us.end()) {
//                 curr = next;
//                 us.insert(curr);
//                 ++count;
//                 next = nums[curr];
//             }
//             res = std::max(res, count);
//         }
//         return res;
//     }
// };

// /*
//     √ Accepted
//     √ 856/856 cases passed (40 ms)
//     √ Your runtime beats 19.79 % of cpp submissions
//     √ Your memory usage beats 9.09 % of cpp submissions (14.5 MB)
//  */
// class Solution {
// public:
//     int arrayNesting(vector<int>& nums) {
//         int res = 0;
//         int curr, next;
//         std::unordered_map<int, int> umap;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (umap.find(i) != umap.end()) { continue; }
//             int lastSize = umap.size();
//             curr = i;
//             umap[curr] = 0;
//             next = nums[curr];
//             while (umap.find(next) == umap.end()) {
//                 curr = next;
//                 umap[curr] = 0;
//                 next = nums[curr];
//             }
//             res = std::max(res, int(umap.size()) - lastSize);
//         }
//         return res;
//     }
// };

/*
    Similar to DFS: 
    √ Accepted
    √ 856/856 cases passed (20 ms)
    √ Your runtime beats 82.25 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (9.7 MB)
 */
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        int curr, next;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == -1) { continue; }
            int depth = 0;
            curr = i;
            while (nums[curr] != -1) {
                next = nums[curr];
                nums[curr] = -1;
                ++depth;
                curr = next;
            }
            res = std::max(res, depth);
        }
        return res;
    }
};