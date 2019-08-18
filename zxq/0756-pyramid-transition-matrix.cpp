/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */

/*
    √ Accepted
    √ 63/63 cases passed (16 ms)
    √ Your runtime beats 21 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (9.9 MB)
 */
class Solution {
    string getAllowed(vector<string>& candidates, vector<string>& allowed) {
        string res = "";
        for (auto& candi : candidates) {
            int i;
            for (i = 0; i < allowed.size(); ++i) {
                if (allowed[i].find(candi) == 0) {
                    if (res.find(allowed[i][2]) == string::npos) {
                        res.append(1, allowed[i][2]);
                    }
                    break;
                }
            }
            for (i += 1; i < allowed.size(); ++i) {
                if (allowed[i].find(candi) == 0) {
                    if (res.find(allowed[i][2]) == string::npos) {
                        res.append(1, allowed[i][2]);
                    }
                }
                else {
                    break;
                }
            }
        }
        return res;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        std::sort(allowed.begin(), allowed.end());
        vector<string> upper(bottom.size());
        for (int i = 0; i < bottom.size(); ++i) {
            upper[i] = string(1, bottom[i]);
        }
        for (int rowLen = bottom.size() - 1; rowLen > 0; --rowLen) {
            for (int idx = 0; idx < rowLen; ++idx) {
                vector<string> candidates {};
                for (int i = 0; i < upper[idx].size(); ++i) {
                    for (int j = 0; j < upper[idx+1].size(); ++j) {
                        candidates.push_back(string(1, upper[idx][i]) + string(1, upper[idx+1][j]));
                    }
                }
                upper[idx] = getAllowed(candidates, allowed);
                if (upper[idx] == "") {
                    return false;
                }
            }
        }
        return true;
    }
};

