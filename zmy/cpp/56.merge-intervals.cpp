/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
// 为什么这么慢?
class Solution {
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0]< b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        int n = intervals.size();
        if(n==0) {
            return results;
        }
        sort(intervals.begin(), intervals.end(), comp);
        results.push_back(intervals[0]);
        for(auto& interval: intervals) {
            if(interval[0]<=results.back()[1]) {
                results.back()[1] = max(interval[1], results.back()[1]);
            } else {
                results.push_back(interval);
            }
        }
        return results;
    }
};

