/**
 * 50. Pow(x, n)
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 */

/**
 * Runtime: 8 ms, faster than 10.38% of C++ online submissions for Pow(x, n).
 * Memory Usage: 9.5 MB, less than 5.12% of C++ online submissions for Pow(x, n).
 * 正负区别对待时 要注意有符号型整数的边界
 * 关键就是怎么写快……
 */

class Solution {
public:
    double myPow(double x, int n) {
        unordered_map<int,double> powTable;
        powTable.insert({0,1.0});
        double tmp = n < 0 ? 1.0/x : x;
        powTable.insert({1,tmp});
        return reMyPow(x,(long) n, powTable);
           
    }
    
    double reMyPow(double x,long n,unordered_map<int,double> &powTable) {
        if (powTable.find(n) != powTable.end()) {
            return powTable[n];
        }
        
        if (n < 0) {
            n = -n;
            x = 1.0 / x;
        }
        
        long half = n /2;
        long left = n - half;
        cout << half << " " << left << endl;
        double ret = reMyPow(x,half, powTable) * reMyPow(x,left, powTable);
        powTable.insert({n,ret});
        return ret;
    }
};