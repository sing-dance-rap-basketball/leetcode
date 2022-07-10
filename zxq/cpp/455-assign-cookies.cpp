/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(), end(x)
#define sz(x) (x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) {return 0;}
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                ++i;    
                ++j;
            } else {
                ++j;
            }
        }
        return i;
    }
};
// @lc code=end

