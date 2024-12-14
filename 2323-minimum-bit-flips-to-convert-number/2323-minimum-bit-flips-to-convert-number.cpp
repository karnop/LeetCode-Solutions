class Solution {
public:
    int minBitFlips(int start, int goal) {
    long long xorr = (long long)start ^ (long long)goal;

    int ans = 0; 
    while(xorr) {
        if(xorr&1) ans++;
        xorr>>=1;
    }

    return ans;
}
};