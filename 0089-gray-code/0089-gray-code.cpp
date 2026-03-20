class Solution {
public:
    vector<int> grayCode(int n) {
       int  limit = 1 << n;
        vector<int> res(limit);
        for(int i = 0; i < limit; ++i) res[i] = i ^ (i >> 1);
        return res;
    }
};