/**
 * 70. Climbing Stairs
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * Note: Given n will be a positive integer.
 */

/**
 * Runtime: 4 ms, faster than 58.38% of C++ online submissions for Climbing Stairs.
 * Memory Usage: 8.9 MB, less than 5.10% of C++ online submissions for Climbing Stairs.
 */

class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int,int> Ntable;
        Ntable.insert({1,1});
        Ntable.insert({2,2});
        return D(n, Ntable);
    }
    
    int D(int n, unordered_map<int,int> &Ntable) {
        if (Ntable.find(n) != Ntable.end())
            return Ntable[n];
        else {
            int tmp = D(n-1, Ntable) + D(n-2, Ntable);
            Ntable.insert({n,tmp});
            return tmp;           
        }
    }
};
