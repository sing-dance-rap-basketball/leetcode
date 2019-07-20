/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> results;
        int index = 0;
        int n = intervals.size();
        while(index < n && intervals[index][1] < newInterval[0]) {
            results.push_back(intervals[index++]);
        }

        while(index < n && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index ++;
        }
        results.push_back(newInterval);

        while(index < n) {
            results.push_back(intervals[index++]);
        }
        return results;
    }
};

