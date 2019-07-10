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
- 92\. Reverse Linked List II
  
  官网给的解答很详细，反转链表应该也算一种典型的操作，这题和#206有必要熟练掌握。这题的递归版本也有点意思。

- 109\. Convert Sorted List to Binary Search Tree
  
  爆栈和溢出折腾了我好久，本来打算多想几个解法，现在不想做这道题了，日后再说。

- 138\. Copy List with Random Pointer
  
  初次听说deep copy，这题也涉及了hash table，简单来说就是一一对应上就好了，用unordered_map解决。

- 141\. Linked List Cycle
- 142\. Linked List Cycle II
  
  #141用了双指针的方法，不必多言。#142用hash table的话，思路很简单，但是空间开销大；通过简单的数学推导，可以得出一种利用双指针的方法，空间开销很小，比较有意思。

- 143\. Reorder List
- 147\. Insertion Sort List
- 148\. Sort List
  
  复习了一遍排序算法：冒泡排序，快排，简单插入排序，希尔排序，简单选择排序，堆排序，二路/多路归并排序；计数排序，桶排序，基数排序。

- 160\. Intersection of Two Linked Lists
  
  还没做。

- 203\. Remove Linked List Elements
- 206\. Reverse Linked List
  
  这题可以写循环版本和递归版本，递归版本有点意思。我写的两个版本的代码思路都没问题，就是代码看着臃肿，不改了。

- 234\. Palindrome Linked List
  
  还没做。

- 237\. Delete Node in a Linked List
- 328\. Odd Even Linked List
- 445\. Add Two Numbers II
  
  有点意思。有待优化。