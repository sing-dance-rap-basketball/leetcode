/*
 * @lc app=leetcode id=3 lang=golang
 *
 * [3] Longest Substring Without Repeating Characters
 */
func lengthOfLongestSubstring(s string) int {
	mmap := make(map[rune]int)
	start := 0
	longest := 0
	for i, ch := range s {
		if last1, ok := mmap[ch]; ok && last1 >= start {
			start = last1 + 1
		}
		if i-start + 1 > longest {
			longest = i-start + 1
		}
		mmap[ch] = i
	}
	return longest
}

