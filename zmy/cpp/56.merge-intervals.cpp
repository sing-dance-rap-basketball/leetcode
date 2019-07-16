/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
// 为什么这么慢?
class Solution {
    static bool comp(vector<int> a, vector<int> b) {
        return a[0]< b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        int n = intervals.size();
        if(n==0) {
            return results;
        }
        int cnt = 0;
        results.reserve(n);
        sort(intervals.begin(), intervals.end(), comp);
        results.push_back(intervals[0]);
        for(int i=1; i < n; i++) {
            if(intervals[i][0] <= results[cnt][1]) {
                results[cnt][1] = max(intervals[i][1], results[cnt][1]);
            } else {
                results.push_back(intervals[i]);
                cnt++;
            }
        }
        return results;
    }
};

