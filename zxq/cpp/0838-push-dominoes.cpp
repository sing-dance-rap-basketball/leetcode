/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

/*
  √ 36/36 cases passed (16 ms)
  √ Your runtime beats 96.98 % of cpp submissions
  √ Your memory usage beats 98.82 % of cpp submissions (11.3 MB)
  √ 36/36 cases passed (20 ms)
  √ Your runtime beats 95.64 % of cpp submissions
  √ Your memory usage beats 80.47 % of cpp submissions (11.6 MB)
*/
class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.size();
        char lastState = '.';
        int lastSite = -1;
        for (int i = 0; i < len; ++i) {
            if (dominoes[i] == '.') {
                if (lastState == 'R'){
                    dominoes[i] = 'R';
                }
            }
            else if (dominoes[i] == 'R') {
                // dominoes[i] = 'R';
                lastState = 'R';
                lastSite = i;
            }
            else if (dominoes[i] == 'L') {
                if (lastState != 'R') {
                    for (int j = lastSite+1; j < i; dominoes[j] = 'L', ++j);
                }
                else {
                    if ((lastSite + i) % 2 == 0) {
                        dominoes[(lastSite + i) / 2] = '.';
                    }
                    for (int j = (lastSite + i) / 2 + 1; j < i; dominoes[j] = 'L', ++j);
                }
                lastState = 'L';
                lastSite = i;
            }
        }
        return dominoes;
    }
};

