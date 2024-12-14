class Solution {
public:
    bool isPowerOfTwo(int k) {
        if(k < 1) return false;
        long n = k;
        return !(n & (n-1));
    }
};