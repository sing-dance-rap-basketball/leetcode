# 随便写个标题

## 3. Longest Substring Without Repeating Characters
- Approach 1: Brute Force
- Approach 2: Sliding Window
- Approach 3: Sliding Window Optimized

## 992. Subarrays with K Different Integers
做完#3，就去做类似的#992，大概还是双指针，或者说`sliding window`的思路。

虽然是hard，看着不难，以为一小时搞定，结果搞了三个小时，回过头一看其实很简单。（我摔）

## Linked List
先刷`Linked List`这个Tag下面的题目。

- 2\. Add Two Numbers
- 19\. Remove Nth Node From End of List
- 21\. Merge Two Sorted Lists
- 23\. Merge k Sorted Lists (⭐)
    
    本题前置题目是#21(Merge Two Sorted Lists)，做完#21再做这个并不难，第一时间想的是给多个链表的`head`排个序，后面不断更新这个排序。

    更新排序过程中我用的是从头到尾搜索，用二分查找应该会更快一些。最后的结果确实很慢，不过空间利用率还可以，有时间优化一下代码。

    前后大概写了两个小时，代码很快就写好了，主要在debug，由于leetcode测试时候的输入包含各种各样的空链表，一直造成`Runtime Error`，RLG。

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
  
  初次听说`deep copy`，这题也涉及了`hash table`，简单来说就是一一对应上就好了，用`std::unordered_map`解决。

- 141\. Linked List Cycle
- 142\. Linked List Cycle II
  
  #141用了双指针的方法，不必多言。#142用`hash table`的话，思路很简单，但是空间开销大；通过简单的数学推导，可以得出一种利用双指针的方法，空间开销很小，比较有意思。

- 143\. Reorder List
- 147\. Insertion Sort List
- 148\. Sort List
  
  复习了一遍排序算法：冒泡排序，快排，简单插入排序，希尔排序，简单选择排序，堆排序，二路/多路归并排序；计数排序，桶排序，基数排序。

  这题我用了二路归并排序，但是感觉还是不够快，空间占用也不够小，有待优化。

  花点时间优化了一下，优化方法是把每次`merge`时候声明的`dummy`和游标指针放到了类内，而不是函数内，然后时间和空间占用都进步了一大截。

- 160\. Intersection of Two Linked Lists
  
  用了哈希表的想法，先把程序跑通，不考虑怎么做到O(1)的空间。我维护了一个关于第一个链表的`std::set`，然后遍历第二个链表并同时查找，理论上速度应该是O(m+nlogm)，运行速度很差；然后我把`std::set`改成了`std::unordered_map`，理论上时间复杂度是O(m+n)，实际表现一般般。

  第二种思路是双指针，先把两个链表都遍历一遍记录他们的长度，然后用双指针同时遍历两个链表（长链表的游标要先走几步），双指针相遇的地方就是交点；这个方法也有个trick，不妨设链表A比链表B短，pA遍历完A之后，把pA放到B的头部，继续同时遍历，pB到达B的尾部时再把pB放到A的头部，继续同时遍历找相遇点。

  第三种思路是让链表A首尾相连，然后用#141和#142的思路判断链表B是否存在环，存在的话找环的入口。

- 203\. Remove Linked List Elements
- 206\. Reverse Linked List
  
  这题可以写循环版本和递归版本，递归版本有点意思。我写的两个版本的代码思路都没问题，就是代码看着臃肿，不改了。

- 234\. Palindrome Linked List
- 237\. Delete Node in a Linked List
- 328\. Odd Even Linked List
- 445\. Add Two Numbers II
  
  有点意思。有待优化。

- 725\. Split Linked List in Parts
- 766\. Toeplitz Matrix
  
  原题很简单，但是如果内存有限，就没那么简单了，还没有深入考虑。

- 835\. Image Overlap
  
  题目很简单，和卷积操作有点像，我的解法打败了77%，有时间研究一下怎么能更快。

- 838\. Push Dominoes
- 850\. Rectangle Area II (⭐)
  
  这题感觉很有趣，留着先不做。

- 908\. Smallest Range I
- 1072\. Flip Columns For Maximum Number of Equal Rows
  
  我用了给行向量分类的思路，中规中矩。跑了好多次，每次都只能快过百分之三十多的人，每次空间占用都击败了100%，看来这题应该有更好的思路。

  还是给行向量分类的思路，之前统计各类数量我用的是数组，现在改成了`std::map`、`std::unordered_map`，速度提高了很多，要注意的一点是`std::vector<int>`没法哈希，需要先转化成`std::string`。

## Array
- 1\. Two Sum
- 5\. Median of Two Sorted Arrays
- 11\. Container With Most Water
- 15\. 3Sum
  
  第一次写出的代码能跑通，但是时间复杂度太差，会超时；第二次的思路是先用`std::sort`排序，然后3Sum转化成2Sum来做，大概能超越一半人，代码优化了一下，好了很多。

- 16\. 3Sum Closest