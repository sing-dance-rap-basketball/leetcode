/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> results;
        if(words.empty() || s.size()<words[0].size()) return results;
        unordered_map<string, int> word_count;
        for(string& word: words) 
            word_count[word]++;
        
        int n = s.size();
        int len = words[0].size();
        int num = words.size();
        int str_len = len*num;
        // https://leetcode.wang/leetCode-30-Substring-with-Concatenation-of-All-Words.html#%E8%A7%A3%E6%B3%95%E4%BA%8C
        for(int i=0; i<len; i++) {
            if(i+str_len > s.size()) break;
            int str_begin = i;
            int w_begin = i;
            unordered_map<string, queue<int>> str_indexes;
            while(str_begin + str_len <= n) {
                if(str_begin+str_len == w_begin) {
                    results.push_back(str_begin);
                }
                string w;
                if(w_begin+len <= n) {
                    w = s.substr(w_begin, len);
                } else {
                    break;
                }
                if(!word_count.count(w)) { // something not in the map occured.
                    str_begin = w_begin + len;
                    str_indexes = unordered_map<string, queue<int>>();
                } else if(str_indexes[w].size() == word_count[w]) {
                    // a word occured more times than required.
                    for(; str_begin<str_indexes[w].front(); str_begin+=len) {
                        str_indexes[s.substr(str_begin, len)].pop();
                    }
                    str_begin = str_indexes[w].front()+len;
                    str_indexes[w].pop();
                    str_indexes[w].push(w_begin);

                } else if (w_begin < str_begin + str_len) {
                    // satisfied the requirements
                    str_indexes[w].push(w_begin);
                }
                w_begin += len;
            }
        }
        return results;

        // for(int i=0; i<n-num*len +1; i++) {
        //     unordered_map<string, int> occured;
        //     int j=0;
        //     for(; j<num; j++) {
        //         string word = s.substr(i+j*len, len);
        //         if(word_count.find(word)!=word_count.end()) {
        //             occured[word]++;
        //             if(occured[word] > word_count[word]) break;
        //         } else break;
        //     }
        //     if( j == num ) results.push_back(i);
        // }
    }
};

