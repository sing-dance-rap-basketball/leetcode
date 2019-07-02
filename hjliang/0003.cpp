/**
 *3. Longest Substring Without Repeating Characters
 *Given a string, find the length of the longest substring without repeating characters.
 */
 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> charMap;
        int sub_s = 0, sub_e = 0, max_length = 0;
        
        for(auto ch = begin(s); ch != end(s); ++ch){
            if(charMap.find(*ch) != charMap.end()){
                charMap[*ch]++;
                while(charMap[*ch] != 1)
                    charMap[s[sub_s++]]--;
            }            
            else{
                charMap.insert({*ch,1});
            }        
            sub_e++;
            
            int length = sub_e - sub_s;
            if(length > max_length){
                max_length = length;
            }
        }
        
        return max_length;
    }
};