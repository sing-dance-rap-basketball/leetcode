# 随便写个标题

## 3. Longest Substring Without Repeating Characters
- Approach 1: Brute Force
- Approach 2: Sliding Window
- Approach 3: Sliding Window Optimized

## 992. Subarrays with K Different Integers
做完 #3，就去做类似的 #992，大概还是双指针，或者说 `sliding window` 的思路。

虽然是 hard，看着不难，以为一小时搞定，结果搞了三个小时，回过头一看其实很简单。（我摔）








## Linked List
先刷 `Linked List` 这个Tag下面的题目。

刷完 `Linked List` 的心得就是没什么心得，毕竟是最基础的数据结构了，查找、插入、删除掌握熟练就好了，有时候自己定义一个 `dummy head` 会让编程方便不少，链表信息不全的时候快慢指针蛮有用的（倒查链表，链表分半，检测环）。

- 2\. Add Two Numbers
- 19\. Remove Nth Node From End of List
- 21\. Merge Two Sorted Lists
- 23\. Merge k Sorted Lists (⭐)
    
    本题前置题目是 #21 (Merge Two Sorted Lists)，做完 #21 再做这个并不难，第一时间想的是给多个链表的 `head` 排个序，后面不断更新这个排序。

    更新排序过程中我用的是从头到尾搜索，用二分查找应该会更快一些。最后的结果确实很慢，不过空间利用率还可以，有时间优化一下代码。

    前后大概写了两个小时，代码很快就写好了，主要在debug，由于leetcode测试时候的输入包含各种各样的空链表，一直造成 `Runtime Error`，RLG。

- 24\. Swap Nodes in Pairs
- 25\. Reverse Nodes in k-Group
    
    思路和 #24 (Swap Nodes in Pairs) 类似，用递归的方法写，比较简单。

- 26\. Rotate List
- 83\. Remove Duplicates from Sorted List
- 82\. Remove Duplicates from Sorted List II
- 86\. Partition List
- 92\. Reverse Linked List II
  
  官网给的解答很详细，反转链表应该也算一种典型的操作，这题和#206有必要熟练掌握。这题的递归版本也有点意思。

- 109\. Convert Sorted List to Binary Search Tree
  
  爆栈和溢出折腾了我好久，本来打算多想几个解法，现在不想做这道题了，日后再说。

- 138\. Copy List with Random Pointer

  初次听说 `deep copy`，这题也涉及了 `hash table`，简单来说就是一一对应上就好了，用 `std::unordered_map` 解决。

- 141\. Linked List Cycle
- 142\. Linked List Cycle II
  
  #141用了双指针的方法，不必多言。#142用 `hash table` 的话，思路很简单，但是空间开销大；通过简单的数学推导，可以得出一种利用双指针的方法，空间开销很小，比较有意思。

- 143\. Reorder List
- 147\. Insertion Sort List
- 148\. Sort List (⭐) 
  
  复习了一遍排序算法：冒泡排序，快排，简单插入排序，希尔排序，简单选择排序，堆排序，二路/多路归并排序；计数排序，桶排序，基数排序。

  这题我用了二路归并排序，但是感觉还是不够快，空间占用也不够小，有待优化。

  花点时间优化了一下，优化方法是把每次 `merge` 时候声明的 `dummy` 和游标指针放到了类内，而不是函数内，然后时间和空间占用都进步了一大截。

- 160\. Intersection of Two Linked Lists (⭐)
  
  用了哈希表的想法，先把程序跑通，不考虑怎么做到 O(1) 的空间。我维护了一个关于第一个链表的 `std::set`，然后遍历第二个链表并同时查找，理论上速度应该是 O(m+nlogm)，运行速度很差；然后我把 `std::set` 改成了 `std::unordered_map`，理论上时间复杂度是 O(m+n)，实际表现一般般。

  第二种思路是双指针，先把两个链表都遍历一遍记录他们的长度，然后用双指针同时遍历两个链表（长链表的游标要先走几步），双指针相遇的地方就是交点；这个方法也有个 trick，不妨设链表 A 比链表 B 短，pA 遍历完 A 之后，把 pA 放到 B 的头部，继续同时遍历，pB 到达 B 的尾部时再把 pB 放到 A 的头部，继续同时遍历找相遇点。

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

  还是给行向量分类的思路，之前统计各类数量我用的是数组，现在改成了 `std::map`、`std::unordered_map`，速度提高了很多，要注意的一点是  `std::vector<int>` 没法哈希，需要先转化成 `std::string`。








## Array
下面是 `Array` Tag 下的题目列表：
- 1\. Two Sum
- 5\. Median of Two Sorted Arrays
- 11\. Container With Most Water
  
  这题看着和#42 (Trapping Rain Water) 挺像，其实完全不一样，这道题用双指针遍历穷举就好了，问题关键点在于合理地让双指针“跳跃前进”，这一点有点意思，实际写起来有点小坑。

- 15\. 3Sum
  
  第一次写出的代码能跑通，但是时间复杂度太差，会超时；第二次的思路是先用 `std::sort` 排序，然后 3Sum 转化成 2Sum 来做，大概能超越一半人，代码优化了一下，好了很多。

- 16\. 3Sum Closest
- 18\. 4Sum
- 26\. Remove Duplicates from Sorted Array
- 27\. Remove Element
- 31\. Next Permutation
  
  这题不难，但是感觉蛮有趣，可能是之前没做过字典序的题。本来想写个递归，写着写着就不用递归了。
  
- 33\. Search in Rotated Sorted Array
  
  二分查找的变体，还是二分查找的思路，想了一下，本质上就是分类讨论。后面有好几道也都是相同的思路。

- 34\. Find First and Last Position of Element in Sorted Array
- 35\. Search Insert Position
- 39\. Combination Sum
  
  这题是典型的不定方程，比 #40 难一点，思路就是遍历穷举，难点就是做到不重不漏、提高运行速度。
  
  做到下面 #78 发现这题和下一题是典型的用回溯解决的题。

- 40\. Combination Sum II
  
  这题是前面 2Sum、3Sum、4Sum 等求和题的集大成者了，思路一样，只不过参与求和的整数数量不确定，用递归好一点。

- 41\. First Missing Positive
  
  题目要求 O(n) 时间，O(1) 额外空间，这是难点所在。我的做法是先用 `std::sort` 排序，然后简单地从头到尾过一遍（中途可以直接跳出），排序的时间复杂度是 O(nlogn)，不过感觉这么做脱离了题目的本意。

  看了网上的讨论，一种解决思路是，维护一个数组标记 `1` 到 `nums.size()-1` 的数是否存在，先遍历 `nums` 一遍，再遍历这个数组一遍，这种思路的改进是不创建新数组，在 `nums` 内部遍历一遍，介于 `1` 到 `nums.size()-1` 的数 `k` 放到 `nums[k-1]` 中，然后遍历第二遍就可以找到目标；另一种解决思路是，先用快排里面的技巧，把数组中的正数放到数组前半段，然后把正数遍历一遍，如果数 `k` 存在，就把 `nums[k-1]` 改为绝对值不变的负数，再遍历一遍前半段，就可以找到目标，这种方法不见得更好，但是感觉这种标记方法很有趣。

- 42\. Trapping Rain Water
  
  不愧是 `hard`，比前面的题有意思一点，不过我蹲个坑的时间就想出来了，我的做法是双指针遍历，一个水坑一个水坑地累加起来。Top Voted Solution 里面有个7行的 c++ 解法，真是秀得一批，都没怎么看懂。

- 45\. Jump Game II

  感觉这是一道比较水的 `hard`，看完题我就直接开写，我用的应该是动态规划（？）；写完差不多就跑通了，只不过，最后一种 case 会超时，我针对这个输入样本打了个补丁，然后就 beats 97.28%，感觉这样有点鸡贼，内存占用也不理想，有待优化。

  看了网上的讨论，补了一个广度优先搜索的方法，补了一个贪婪的方法，其实两个方法差不多。
  
- 48\. Rotate Image
  
  方阵顺时针旋转90°，等价于先翻折再转置，so easy！

- 53\. Maximum Subarray
  
  先写了从头到尾走一遍就得出结果的 O(n) 解法，然后按 Follow up 的要求写了个分治的解法，感觉没有前一种好。

- 54\. Spiral Matrix
- 55\. Jump Game
  
  和之前 #45 (Jump Game II) 一样的情况，最后一种超长的 case 会超时。

  读了官方解答，发现我的方法和他的 bottom-up dynamic programming 方法类似，不过我的方法中间有一步可以优化，所以我之前超时了。这题最好的解法是用 greedy。

- 56\. Merge Intervals
  
  这个题是求闭区间的并，有两个坑：
  - 给区间排序的时候用 `std::sort`，需要手写一个比较函数，开始在类内写了一个非静态成员函数，结果报错，有三种解决方法，第一种是写成静态成员函数（此时可以用 `Solution::compareInterval` 调用），第二种是用 `lambda` 函数，第三种是用 `std::bind` （这个不会）。
  - 区间排序函数我本来写的是 `v1[0] <= v2[0]`，然后提交之后会 `Runtime error`，`<=` 改成 `<` 之后就打败了99%，好坑啊；从网上查反正就是用 `<` 和 `>` 更好一点，而且仿佛能保序（存疑），以后详细研究一下 `std::sort`。

- 57\. Insert Interval
  
  虽然是 `hard`，但是感觉没多难，看到题就有思路，一会儿就写完提交被接受了，注意考虑情况要全面。

- 59\. Spiral Matrix II
- 62\. Unique Paths
  
  动态规划的题，用递归的方法会 `Runtime error`；简单推导一下发现结果是二项式系数，然后算组合数就可以了，注意算的过程中用 `long` 保存中间结果；像下一题一样把矩阵遍历一遍应该也是个不错的方法，没有写这种方法。

- 63\. Unique Paths II
  
  还是动态规划的题，和上一题 #62 不同的是，上一题是终点到起点的思路，这一题因为有障碍物，所以用起点到终点的思路，把整个格点矩阵逐行遍历一遍结果就出来了；需要注意的是，中间结果用 `long` 保存，我写的中间结果是用 n 行 m 列的矩阵保存的，空间占用较大，可以优化成只用两行甚至一行。

- 64\. Minimum Path Sum
  
  和前两题差不多。

- 66\. Plus One
- 73\. Set Matrix Zeroes
- 74\. Search a 2D Matrix
- 75\. Sort Colors
  
  用计数排序巨简单；不用计数排序，只过一遍（One-pass）也可以，用双指针的方法，写了半天才写出来。

- 78\. Subsets

  写了一个利用位运算的版本，这题最典型的做法是用回溯，回溯不太会写，需要学习一下。

  补上了一个回溯的版本，和 Top voted solution 学的。

- 79\. Word Search
  
  之前没写过回溯，写了一个多小时，成功写成，nice！就是很慢，有待优化。

  参考了 Top voted solution 里面的 `DFS` 方法，其实感觉和我的思路差不多，但是各处细节都有优化，我感觉最主要优化的地方就是“擦除”经过的元素。

- 80\. Remove Duplicates from Sortd Array II
- 81\. Search in Rotated Sorted Array II

  比 #33 (Search in Rotated Sorted Array) 麻烦一些，写了半天，照顾细节，然后一遍过，苏福。

  不过看了一下，别人的方法更秀，代码优化无止境。

- 84\. Largest Rectangle in Histogram

  写了一个用了栈思路的解法，ac了，但是很慢。

- 85\. Maximal Rectangle
- 88\. Merge Sorted Array
- 90\. Subsets II
  
  逐渐会写回溯了，这题基于 #78 (Subsets) 稍作改动就好。

- 105\. Construct Binary Tree from Preorder and Inorder Traversal
- 118\. Pascal's Triangle
- 119\. Pascal's Triangle II
- 120\. Triangle
- 121\. Best Time to Buy and Sell Stock
- 122\. Best Time to Buy and Sell Stock II
  
  #162 和 #852 中提到了 peak，这题的思路有所借鉴，用相邻的右边的 peak 减去 左边的 peak，完成一次交易，所有的交易加起来得出结果。

- 123\. Best Time to Buy and Sell Stock III

  本来想借鉴上一题的思路，从所有交易中找到最大的两次交易，但是发现事情并不那么简单。

  整了一个 `vector` 记录 `prices` 中依次出现的 valley 和 peak；然后把 `vector` 分成前后两段，每段用 #121 的思路求相应的 max_profit，两个 max_profit 加起来；把 `vector` 多次分段，找最大的和即可。

  看了一下官网上的[题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/)，发现买卖股票的题有很多道，可以用动态规划的方法来做，打算抽个时间把这几道一起做一下。动态规划的关键是要搞清楚怎么描述状态，进而描述状态之间的转移。

- 126\. Word Ladder II
- 128\. Longest Consecutive Sequence
  
  先试了试笨办法，先排序，然后从头到尾遍历一遍，时间复杂度明显不是 O(N)，但 ac 了，还挺快。

  还有种思路是先把数字都加到 hash 表里面，然后用类似 brute force 的方法。

  然后在代码里实现了一个并查集的类，类中算法用到了 weighted quick-union with path compression，union 和 find 的时间复杂度都近乎线性；实现了并查集的类之后发现并不知道怎么以线性时间复杂度解决这道题；在网上的 discussion 里面 copy 了一份用并查集的解法，感觉并没有前两种方法好。
  
  做这题的时候还发现了一个小坑，使用容器的 `size()` 方法时，如果 `stl.size()` 是 `0u`，`stl.size()-1` 会是一个很大的正数，这点要注意，此时尽量用 `empty()` 方法单独判断。

- 152\. Maximum Product Subarray
  
  Maximum Subarray 类型的问题，从 discussion 学到了一种蛮有意思的解法。

- 153\. Find Minimum in Rotated Sorted Array
- 154\. Find Minimum in Rotated Sorted Array II
- 162\. Find Peak Element
- 167\. Two Sum II - Input array is sorted
- 169\. Majority Element
  
  这个题看着很简单，但是做法很多，哈希、排序、随机、分治、位操作都可以，还有一种没听过的方法是 Boyer–Moore majority vote algorithm，这个方法很有趣。

- 189\. Rotate Array
- 209\. Minimum Size Subarray Sum
  
  一道中等难度但是蛮有趣的双指针的题。

- 216\. Combination Sum III
- 217\. Contains Duplicate
- 219\. Contains Duplicate II
- 228\. Summary Ranges
- 229\. Majority Element II
- 238\. Product of Array Except Self
- 268\. Missing Number
- 283\. Move Zeroes
- 287\. Find the Duplicate Number
  
  想了半天也没想到二分查找还能这么用，没绕过来这个弯。除了二分查找，还有一种快慢指针的思路，看起来更有趣。

- 289\. Game of Life
  
  想了个小点子，用十位表示新状态，个位表示愿状态，这样第一次遍历就可以 in-place 更新了，感觉还不错。

  官方给的解答也是类似的思路，1->0 用 -1 表示，0->1 用 2 表示。

  这个问题的 follow-up 讨论了解法的可扩展性，即题目中给的矩阵大小很大的时候，如何处理，一方面要考虑一次读取一部分数据到内存中，另一方面当 live cell 很稀疏的时候，最好只考虑 live cell 的位置。

- 414\. Third Maximum Number
- 442\. Find All Duplicates in an Array
  
  这题和 #448 用了同一个技巧，就是用数组中第 i 个元素的性质（正负等）标识整数 i 是否存在。

- 448\. Find All Numbers Disappeared in an Array
- 457\. Circular Array Loop
  
  题目比较没劲，不过做这个题我发现在 C++ 里面，`-7/2=-1`，整数除法求余数是根据商的结果计算出来的。

- 485\. Max Consecutive Ones
- 495\. Teemo Attacking
- 532\. K-diff Pairs in an Array
- 560\. Subarray Sum Equals K
  
  做了这道题掌握了一个关于 `std::map` 和 `std::unordered_map` 的知识点，使用下标访问不存在的 key 的时候，会为这个 key 生成一个默认的 value，使用 `at()` 方法访问不存在的 key 的时候，会报 out-of-range。

- 561\. Array Partition I
- 565\. Array Nesting
- 566\. Reshape the Matrix
- 581\. Shortest Unsorted Continuous Subarray
  
  这题标的是 easy，虽然确实不是很难，但感觉也不是 easy 的程度，而且这题蛮有意思的。

- 605\. Can Place Flowers
- 611\. Valid Triangle Number
- 621\. Task Scheduler
- 628\. Maximum Product of Three Numbers
- 643\. Maximum Average Subarray I
- 661\. Image Smoother
  
  垃圾题目，code 半小时，debug 半小时，bug 原因是有一个方括号错写成了花括号，找得眼睛都瞎了。

- 665\. Non-decreasing Array
  
  感觉和 #581 有一丢丢相似。

- 667\. Beautiful Arrangement II
- 670\. Maximum Swap
- 674\. Longest Continuous Increasing Subsequence
- 689\. Maximum Sum of 3 Non-Overlapping Subarrays
  
  这个题有点意思，最开始写了个套娃式的解法，经过 debug 发现这个思路有缺陷。

- 695\. Max Area of Island
  
  debug 花了一个小时，bug 原因是在 dfs 过程中，对已遍历的元素，应该有一步 `grid[i][j] = 0`，我写成了 `grid[i][j] == 0`，吐血了。

- 697\. Degree of an Array
- 713\. Subarray Product Less Than K
- 714\. Best Time to Buy and Sell Stock with Transaction Fee
  
  暂时不做，留到后面研究动态规划的时候再做。

- 717\. 1-bit and 2-bit Characters
- 718\. Maximum Length of Repeated Subarray
  
  这题蛮有意思，解法超时了，暂时没想出新解法。

- 719\. Find K-th Smallest Pair Distance
- 724\. Find Pivot Index
- 729\. My Calendar I
- 747\. Largest Number At Least Twice of Others
- 748\. Shortest Completing Word
- 756\. Pyramid Transition Matrix
- 777\. Swap Adjacent in LR String
- 779\. K-th Symbol in Grammar
- 780\. Reaching Points
  
  是道 hard，但是没多大时间就 ac 了，有点辗转相除法的意思，蛮有趣。

- 790\. Domino and Tromino Tiling
  
  会一步步手算，暂时没推出公式解，通过观察部分结果，归纳出递推性质：
  $$
  a_n = 2 \times a_{n-1} + a_{n-3} \qquad (n > 3)
  $$
  看了 discussion，大概想明白了，用动态规划的思路，不妨设 $a_0 = 1$，初始条件是 $a_1 = 1$ 和 $a_2 = 2$，考虑一般的 $a_n (n \geq 3)$，由三部分组成：
  
  - 对于宽为 $n-1$ 的情形，右边再放一个竖条，这部分数量是 $a_{n-1}$；
  - 对于宽为 $n-2$ 的情形，右边再放两个横条（即一个 $2\times 2$），这部分数量是 $a_{n-2}$；
  - 对于宽为 $0$ 到 $n-3$ 的情形，右边相应地要再放宽为 $n$ 到 $3$ 的一条，每种情形有两种方式（这里指的是不能拆分成更小宽度的方式），这部分数量是 $2 \times \sum_{0}^{n-3} a_i$；
  
  综上，

  $$
  a_n = a_{n-1} + a_{n-2} + 2 \times \sum_{0}^{n-3} a_i
    = a_{n-1} + a_{n-3} + (a_{n-2} + a_{n-3} + 2 \times \sum_{0}^{n-4} a_i)
    = a_{n-1} + a_{n-3} + a_{n-1}
    = 2 \times a_{n-1} + a_{n-3}
  $$

- 798\. Smallest Rotation with Highest Score
  
  这题很有趣，最开始写的最笨的 `O(N^2)` 的方法果然超时；然后写了一个更好的 `O(N^2)` 的方法，对每一个元素统计能使它得分的转动量 `K`，更快了一些，但还是会超时，稍稍优化一下，勉勉强强 ac 了；后来看了 discussion 里面好多个讨论，看懂了[这位网友的解释](https://leetcode.com/problems/smallest-rotation-with-highest-score/discuss/118725/C%2B%2BJavaPython-Solution-with-Explanation)，非常感谢他。

  这题的关键就是，对于每一个元素，能使他得分（或者失分）的转动量 `K` 构成了一个区间（也可能是两个），如何以 `O(N)` 的时间复杂度，找到所有区间中出现次数最多的 `index`。对于区间 `[a,b]`，可以写成 `[a,b+1)`，假设这是一个得分区间，然后维护一个数组，数组第 `a` 项加 1，数组第 `b+1` 项减 1，然后从头到尾累加，就可以得到每项的正确的分数。这个思路很巧妙，学习了。

- 808\. Soup Servings
- 811\. Subdomain Visit Count
- 852\. Peak Index in a Mountain Array
  
  Mountain Array

- 857\. Minimum Cost to Hire K Workers
- 861\. Score After Flipping Matrix
- 864\. Shortest Path to Get All Keys
- 870\. Advantage Shuffle
- 879\. Profitable Schemes
- 898\. Bitwise ORs of Subarrays
  
  brute force -> frontier set

  Time Complexity: O($N \log W$), where `N` is the length of `A`, and `W` is the maximum size of elements in `A`.

  Space Complexity: O($N \log W$), the size of the answer.
  
- 901\. Online Stock Span
- 905\. Sort Array By Parity
- 924\. Minimize Malware Spread
- 927\. Three Equal Parts
- 932\. Beautiful Array
- 936\. Stamping The Sequence
- 941\. Valid Mountain Array
- 943\. Find the Shortest Superstring
- 