/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		list<char> s1;
		int l = s.size();
		cout << s.size() << endl;
		unsigned length = 0;
		if (s.size() == 1)
			return 1;
		if (s.size() == 0)
			return 0;
		for (int i = 0; i < l; i++)
		{
			if (s1.empty())
				s1.push_back(s[i]);
			else
			{
				for (list<char>::iterator iter = s1.begin(); iter != s1.end(); iter++)
				{
					if (*iter == s[i])
					{
						if (s1.size()>length)
							length = s1.size();
						while (*s1.begin() != s[i])
							s1.pop_front();
						s1.pop_front();
						break;
						//	s1.push_back(s[i]);
					}


				}
				s1.push_back(s[i]);
			}
		}
		return s1.size()>length?s1.size():length;
	}
};
