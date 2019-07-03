#
# 问题描述：
# 3. Longest Substring Without Repeating Characters1. Two Sum
# Given a string, find the length of the longest substring without repeating characters.

# 其他人的解法

def lengthOfLongestSubstring(self, s):
    dct = {}
    max_so_far = curr_max = start = 0
    for index, i in enumerate(s):
        if i in dct and dct[i] >= start:
            max_so_far = max(max_so_far, curr_max)
            curr_max = index - dct[i]
            start = dct[i] + 1
        else:
            curr_max += 1
        dct[i] = index
    return max(max_so_far, curr_max)

def lengthOfLongestSubstring(self, s):
    dicts = {}
    maxlength = start = 0
    for i,value in enumerate(s):
        if value in dicts:
            sums = dicts[value] + 1
            if sums > start:
                start = sums
        num = i - start + 1
        if num > maxlength:
            maxlength = num
        dicts[value] = i
    return maxlength