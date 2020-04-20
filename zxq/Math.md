# Math

## 2 Add Two Numbers

## 7 Reverse Integer

## 8 String to Integer (atoi)

平平无奇，注意细节，无非就是分类讨论．

## 9 Palindrome Number

## 12 Integer to Roman

罗马数字中的 1、5、10、50、100、500、1000 分别是 I、V、X、L、C、D、M．

在字符串后面拼接字符或字符串有以下几种方式：
- 用 `string` 的 `push_back()` 方法附加一个字符；
- 用 `string` 的 `append()` 方法附加一定个数的字符、字符串、字符串的子串等；
- 用 `string` 的 `+` 或 `+=` 操作符；
- 用 C 语言中的 `strcat` 函数．

## 13 Roman to Integer

## 29 Divide Two Integers

从被除数中不断减去除数，为了减得快一点，第一次减 1 个，第二次减 2 个，第三次减 4 个，以此类推．

## 43 Multiply Strings

字符串数学计算类型的问题。这题用了快速笔算乘法的一个思路，而不是小学学的乘法竖式（进位乘法）思路，注意乘积位数的细节．

看了社区里的讨论，乘法竖式也很简单，代码如下．

```c++
string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    string ans(m + n, '0');
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
            ans[i + j + 1] = sum % 10 + '0';
            ans[i + j] += sum / 10;
        }
    }
    for (int i = 0; i < m + n; i++) {
        if (ans[i] != '0') {
            return ans.substr(i);
        }
    }
    return "0";
}
```

## 50 Pow(x, n)

跟 #29 思路一样．

## 60 Permutation Sequence (⭐)

按字典序找第 $k$ 小的 $n$ 排列．我的思路是先找首位数字，然后在 $1$ 到 $n$ 中删去首位数字，其余数字由小到大的顺序不变，再继续找第二位数字，以此类推．没有用回溯的思路．优化后的代码如下：

```c++
string getPermutation(int n, int k) {
    string ans(n, '0');
    
    vector<int> nums(n, 1);
    for (int i = 0; i < n; ++i) {
        nums[i] += i;
    }

    vector<int> factorial(n+1, 1);
    for (int i = 2; i <= n; ++i) {
        factorial[i] = factorial[i-1] * i;
    }

    for (int i = n-1, j = k-1; i >= 0; --i) {
        ans[n - 1 - i] += nums[j / factorial[i]];
        nums.erase(nums.begin() + (j / factorial[i]));
        j %= factorial[i];
    }

    return ans;
}
```

上面代码中有一个小技巧是，因为要计算的阶乘较少，所以直接生成一个阶乘表，不需要另写一个函数；事实上，还可以进一步改进，代码中求的阶乘每次减一，所以只需要维持一个记录阶乘值的整数，每次用它计算下一次的阶乘．

## 65 Valid Number

这题虽然是 `hard`，但是感觉难度不大，学习了几个 `string` 的成员函数：
- `string::find`
  - string (1)      `size_t find (const string& str, size_t pos = 0) const noexcept;`
  - c-string (2)    `size_t find (const char* s, size_t pos = 0) const;`
  - buffer (3)	    `size_t find (const char* s, size_t pos, size_type n) const;`
  - character (4)	`size_t find (char c, size_t pos = 0) const noexcept;`
- `string::erase`
  - sequence (1)	`string& erase (size_t pos = 0, size_t len = npos);`
  - character (2)	`iterator erase (const_iterator p);`
  - range (3)	    `iterator erase (const_iterator first, const_iterator last);`
- `string::substr`
  - `string substr (size_t pos = 0, size_t len = npos) const;`
- `string::find_first_not_of`: omit
- `string::find_last_not_of`: omit

## 67 Add Binary

## 69 Sqrt(x)

## 149 Max Points on a Line

看了[这个分享](https://leetcode.com/problems/max-points-on-a-line/discuss/47117/Sharing-my-simple-solution-with-explanation)，思路不是很复杂，固定一个点，用哈希表记录该点与其他点连线，哈希表的 `key`：
- 用斜率是一种思路，此时斜率是一个浮点数，`unordered_map` 可以直接用；
- 我选择的是直线的方向向量，向量要化简，化简时注意直线斜率不存在的情形；`pair` 作为 `unordered_map` 的 `key` 需要为 `pair` 添加 `hash` 函数，参见[这一文章](https://blog.csdn.net/sinat_35261315/article/details/76473867)；`pair` 作为 `map` 的 `key` 没有这种问题．

注意输入为空的情形，最坑的是要注意重复的点．

## 166 Fraction to Recurring Decimal

有点意思，还没做．

## 168 Excel Sheet Column Title

挺简单的题，做错了好多遍，注意不是简单的求余数和除法．

## 171 Excel Sheet Column Number

## 172 Factorial Trailing Zerose

## 202 Happy Number

## 204 Count Primes (⭐)

这题还是有点意思的，数比 $n$ 小的素数数量．

第一种思路就是一个个判断素数，维护一个以确定的素数表可以更省事．

第二种思路是从小到大，如果是素数，就把以它为因数的合数都标记出来，这种方法占用空间多一点，但是更快．代码中针对这个思路优化了好几版，最后一版借鉴了[这个分享](https://leetcode.com/problems/count-primes/discuss/57593/12-ms-Java-solution-modified-from-the-hint-method-beats-99.95)，很精致．

## 223 Rectangle Area

还没做

## 224 Basic Calculator

还没做

## 231 Power of Two

`n & (n-1)`

## 233 Number of Digit One

从个位开始，依次统计每一位出现的 1 的个数，这种思路比较简单。

## 258 Add Digits

弃九验算法．

## 263 Ugly Number

## 264 Ugly Number II (⭐)

这个题用了动态规划，思路很精致。

## 268 Missing Number

可以利用异或的交换律和结合律，找出目标．通过处理数组中数的范围来标定下标也是一种思路，但是容易出 bug，没写这种方法．

## 273 Integer to English Words

这题达不到 `hard` 的难度，就是需要分类讨论 +　注意细节．

## 279 Perfect Squares

按我的思路写了个 bfs + dp，过了但是很慢，有待优化．

## 313 Super Ugly Number

一种做法是依照 `#264 Ugly Number II` 的动态规划的思路。

另一种做法用堆，Python 代码如下
```python
def nthSuperUglyNumber(self, n, primes):
    uglies = [1]
    def gen(prime):
        for ugly in uglies:
            yield ugly * prime
    merged = heapq.merge(*map(gen, primes))
    while len(uglies) < n:
        ugly = next(merged)
        if ugly != uglies[-1]:
            uglies.append(ugly)
    return uglies[-1]
```

应该还有更优化的方法，不想细究了。

## 319 Bulb Switcher

这题利用了只有完全平方数有奇数个因数的性质．

## 326 Power of Three

这题没有 `#231 Power of Two` 用到的小技巧，只能一个一个除以 3．有一个骚操作是，`int` 范围内最大的 3 的幂是 $3^{19} = 1162261467$，直接判断是不是这个数的因数就可以了．

## 343 Integer Break

动态规划的思路。

这题也可以从数学的角度思考，找出最优方案，一个大于 3 的数恰好拆成 2 和 3 的和，此时乘积最大，具体解释参考[链接](https://leetcode.com/problems/integer-break/discuss/80721/Why-factor-2-or-3-The-math-behind-this-problem.)。

## 357 Count Numbers with Unique Digits

这题求 $S(n) = \# \{x \in \N \vert x < 10^n \}$，数学推导即可，$S(0) = 1$，$S(1) = 10$，$n > 1$ 时，

$$
S(n) = S(n-2) + P_{10}^{n} + (n-2)P_{9}^{n-2}
$$

另一种思路是，考虑 $T(n) = \# \{x \in \N \vert 10^{n-1} \leq x < 10^n, \ n > 0 \}$，有

$$
T(n) = P_{10}^{n} - P_{9}^{n-1} = 9P_{9}^{n-1}
$$

## 367 Valid Perfect Square

## 372 Super Pow

一个简单的利用同余性质的问题，没什么特别之处，感觉自己这题的代码写得不错．

## 396 Rotate Function

找 $F(k)$ 的增长规律即可．

## 397 Integer Replacement

## 400 Nth Digit

## 413 Arithmetic Slices

## 423 Reconstruct Original Digits from English

## 441 Arranging Coins

## 453 Minimum Moves to Equal Array Elements

## 462 Minimum Moves to Equal Array Elements II

## 483 Smallest Good Base

## 507 Perfect Number

## 517 Super Washing Machines

## 523 Continuous Subarray Sum

## 537 Complex Number Multiplication

字符串数学计算类型的问题。整数、浮点数转为字符串，可以用 `std::to_string()` 或 `stringstream`．反过来，字符串转为整数、浮点数，可以用 `stringstream`，C++ 中 `std::stoi()` 系列的函数，C 中 `atoi()` 系列的函数，还有 `sscanf`．

## 553 Optimal Division

这道题出得好蠢啊。

## 593 Valid Square

给定四个点，判断能否构成正方形，计算可以连成的六条线段的长度平方，其中四条短的长度相同，另外两条长的长度相同，且长度平方有个 2 倍的关系．

## 598 Range Addition II

## 633 Sum of Square Numbers

## 640 Solve the Equation

字符串数学计算类型的问题，做起来真蛋疼。

## 645 Set Mismatch

利用数组下标做标记。

## 670 Maximum Swap

## 672 Bulb Switcher II

把所有可能的情况穷举即可。

## 728 Self Dividing Numbers

## 754 Reach a Number

题目内容有点意思，算是一个数学小问题，思路跟[官方解答](https://leetcode.com/problems/reach-a-number/solution/)一样。

## 790 Domino and Tromino Tiling (✨)

递推。用动态规划的思路，不妨设 $a_0 = 1$，初始条件是 $a_1 = 1$ 和 $a_2 = 2$，考虑一般的 $a_n (n \geq 3)$，由三部分组成：

- 对于宽为 $n-1$ 的情形，右边再放一个竖条，这部分数量是 $a_{n-1}$；
- 对于宽为 $n-2$ 的情形，右边再放两个横条（即一个 $2\times 2$），这部分数量是 $a_{n-2}$；
- 对于宽为 $0$ 到 $n-3$ 的情形，右边相应地要再放宽为 $n$ 到 $3$ 的一条，每种情形有两种方式（这里指的是不能拆分成更小宽度的方式），这部分数量是 $2 \times \sum_{0}^{n-3} a_i$；

综上，

$$
\begin{align}
a_n &= a_{n-1} + a_{n-2} + 2 \times \sum_{0}^{n-3} a_i \\
    &= a_{n-1} + a_{n-3} + (a_{n-2} + a_{n-3} + 2 \times \sum_{0}^{n-4} a_i) \\
    &= a_{n-1} + a_{n-3} + a_{n-1} \\
    &= 2 \times a_{n-1} + a_{n-3}
\end{align}
$$

## 796 Rotate String

有趣的简单题，我用了最笨的方法，更好的思路是把 `A` 和 `A` 拼接起来，判断 `B` 是否是其子串，[官方解答](https://leetcode.com/problems/rotate-string/solution/)在此基础上给了好几种方法，没有细看。

## 798 Smallest Rotation with Highest Score (✨)

这题很有趣，最开始写的最笨的 `O(N^2)` 的方法果然超时；然后写了一个更好的 `O(N^2)` 的方法，对每一个元素统计能使它得分的转动量 `K`，更快了一些，但还是会超时，稍稍优化一下，勉勉强强 ac 了；后来看了 discussion 里面好多个讨论，看懂了[这位网友的解释](https://leetcode.com/problems/smallest-rotation-with-highest-score/discuss/118725/C%2B%2BJavaPython-Solution-with-Explanation)，非常感谢他。

这题的关键就是，对于每一个元素，能使他得分（或者失分）的转动量 `K` 构成了一个区间（也可能是两个），如何以 `O(N)` 的时间复杂度，找到所有区间中出现次数最多的 `index`。对于区间 `[a,b]`，可以写成 `[a,b+1)`，假设这是一个得分区间，然后维护一个数组，数组第 `a` 项加 1，数组第 `b+1` 项减 1，然后从头到尾累加，就可以得到每项的正确的分数。这个思路很巧妙，学习了。

## 830 Positions of Large Groups

## 856 Score of Parentheses

我用了栈的思路和递归的写法。[这个解答](https://leetcode.com/problems/score-of-parentheses/discuss/141777/C%2B%2BJavaPython-O(1)-Space)很巧妙，想不到，代码如下：

```C++
int scoreOfParentheses(string S) {
    stack<int> stack;
    int cur = 0;
    for (char i : S)
        if (i == '(') {
            stack.push(cur);
            cur = 0;
        }
        else {
            cur += stack.top() + max(cur, 1);
            stack.pop();
        }
    return cur;
}
```