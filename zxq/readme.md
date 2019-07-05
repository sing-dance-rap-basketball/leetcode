# 随便写个标题

## 3. Longest Substring Without Repeating Characters
- Approach 1: Brute Force
- Approach 2: Sliding Window
- Approach 3: Sliding Window Optimized

## 992. Subarrays with K Different Integers
做完#3，就去做类似的#992，大概还是双指针，或者说sliding window的思路。

虽然是hard，看着不难，以为一小时搞定，结果搞了三个小时，回过头一看其实很简单。（我摔）

## Linked List
先刷"Linked List"这个Tag下面的题目。

- 2\. Add Two Numbers
- 19\. Remove Nth Node From End of List
- 21\. Merge Two Sorted Lists
- 23\. Merge k Sorted Lists (⭐)
    
    本题前置题目是#21(Merge Two Sorted Lists)，做完#21再做这个并不难，第一时间想的是给多个链表的head排个序，后面不断更新这个排序。

    更新排序过程中我用的是从头到尾搜索，用二分查找应该会更快一些。最后的结果确实很慢，不过空间利用率还可以，有时间优化一下代码。

    前后大概写了两个小时，代码很快就写好了，主要在debug，由于leetcode测试时候的输入包含各种各样的空链表，一直造成Runtime Error，RLG。

- 24\. Swap Nodes in Pairs
- 25\. Reverse Nodes in k-Group
    
    思路和#24(Swap Nodes in Pairs)类似，用递归的方法写，比较简单。

- 26\. Rotate List
- 83\. Remove Duplicates from Sorted List
- 82\. Remove Duplicates from Sorted List II
- 86\. Partition List
- 206\. Reverse Linked List
  
  这题可以写循环版本和递归版本，递归版本有点意思。我写的两个版本的代码思路都没问题，就是代码看着臃肿，不改了。

- 92\. Reverse Linked List II