/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// /*
//     √ Accepted
//     √ 64/64 cases passed (60 ms)
//     √ Your runtime beats 66.32 % of cpp submissions
//     √ Your memory usage beats 46.81 % of cpp submissions (9.9 MB)
//  */
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         int len = tasks.size();
//         std::unordered_map<char, int> umap;
//         for (auto c : tasks) {
//             ++umap[c];
//         }
//         std::vector<int> temp {};
//         for (char c = 'A'; c <= 'Z'; ++c) {
//             if (umap[c] * (n+1) >= len + n) {
//                 temp.push_back(umap[c]);
//             }
//         }
//         if (!temp.empty()) {
//             std::sort(temp.begin(), temp.end());
//             int i = temp.size() - 1;
//             for (; i-1 >= 0 && temp[i-1] == temp[i]; --i);
//             int count = temp.size() - i;
//             return (temp.back() - 1) * (n + 1) + count;
//         }
//         return int(tasks.size());
//     }
// };

/*
    √ Accepted
    √ 64/64 cases passed (52 ms)
    √ Your runtime beats 94.83 % of cpp submissions
    √ Your memory usage beats 80.85 % of cpp submissions (9.7 MB)
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int> temp(26);
        for (auto c : tasks) {
            ++temp[c - 'A'];
        }
        std::sort(temp.begin(), temp.end());
        int i = temp.size() - 1;
        for (; i-1 >= 0 && temp[i-1] == temp[i]; --i);
        int count = temp.size() - i;
        return std::max(int(tasks.size()), (temp.back() - 1) * (n + 1) + count);
    }
};