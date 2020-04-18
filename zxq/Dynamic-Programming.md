# Dynamic Programming

**动态规划**（英语：Dynamic programming，简称DP）是一种通过把原问题分解为相对简单的子问题的方式求解复杂问题的方法。
- 动态规划在查找有很多**重叠子问题**的情况的最优解时有效。它将问题重新组合成子问题。为了避免多次解决这些子问题，它们的结果都逐渐被计算并被保存，从简单的问题直到整个问题都被解决。因此，动态规划保存递归时的结果，因而不会在解决同样的问题时花费时间。
- 动态规划只能应用于有**最优子结构**的问题。最优子结构的意思是局部最优解能决定全局最优解（对有些问题这个要求并不能完全满足，故有时需要引入一定的近似）。简单地说，问题能够分解成子问题来解决。

## 264 Ugly Number II (⭐)

这个题用了动态规划，思路很精致。

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

## 343 Integer Break

动态规划的思路。

这题也可以从数学的角度思考，找出最优方案，一个大于 3 的数恰好拆成 2 和 3 的和，此时乘积最大，具体解释参考[链接](https://leetcode.com/problems/integer-break/discuss/80721/Why-factor-2-or-3-The-math-behind-this-problem.)。
