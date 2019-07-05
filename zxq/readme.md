# 随便写个标题

## 3. Longest Substring Without Repeating Characters
- Approach 1: Brute Force
- Approach 2: Sliding Window
- Approach 3: Sliding Window Optimized

## 992. Subarrays with K Different Integers
做完#3，就去做类似的#992，大概还是双指针，或者说sliding window的思路。

虽然是hard，看着不难，以为一小时搞定，结果搞了三个小时，回过头一看其实很简单。（我摔）

## 23. Merge k Sorted Lists (✨⭐)
先刷"Linked List"这个Tag下面的题目。

本题前置题目是#21(Merge Two Sorted Lists)，做完#21再做这个并不难，第一时间想的是给多个链表的head排个序，后面不断更新这个排序。
更新排序过程中我用的是从头到尾搜索，用二分查找应该会更快一些。最后的结果确实很慢，不过空间利用率还可以，有时间优化一下代码。

前后大概写了两个小时，代码很快就写好了，主要在debug，由于leetcode测试时候的输入包含各种各样的空链表，一直造成Runtime Error，RLG。

## 25. Reverse Nodes in k-Group
思路和#24(Swap Nodes in Pairs)类似，用递归的方法写，比较简单。