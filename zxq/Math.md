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

这题用了快速笔算乘法的一个思路，而不是小学学的乘法竖式（进位乘法）思路，注意乘积位数的细节。

看了社区里的讨论，乘法竖式也很简单，代码如下。

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

跟 #29 思路一样。

## 60 Permutation Sequence

按字典序找第 $k$ 小的 $n$ 排列。我的思路是先找首位数字，然后在 $1$ 到 $n$ 中删去首位数字，其余数字由小到大的顺序不变，再继续找第二位数字，以此类推。没有用回溯的思路。优化后的代码如下：

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

上面代码中有一个小技巧是，因为要计算的阶乘较少，所以直接生成一个阶乘表，不需要另写一个函数；事实上，还可以进一步改进，代码中求的阶乘每次减一，所以只需要维持一个记录阶乘值的整数，每次用它计算下一次的阶乘。

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