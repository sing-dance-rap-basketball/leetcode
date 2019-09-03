class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return vector<int> {0};
        vector<int> ret;
        int mask = (int)pow(2,n) - 1;
        for (int i = 0; i < (int)pow(2,n); ++i) {
            int gray_num = i ^ (i >> 1);
            gray_num &= mask;
            ret.push_back(gray_num);
        }   
        return ret;
    }
};