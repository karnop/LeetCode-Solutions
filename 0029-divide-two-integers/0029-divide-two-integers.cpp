class Solution {
public:
    int divide(int dividend, int divisor) {
    long long x = abs((long long)dividend);
    long long y = abs((long long)divisor);

    bool signd = (dividend < 0) ^ (divisor < 0);

    long long ans = 0;
    while(x >= y)
    {
        long long pow2 = 1, tempdivisor = y;
        while ((tempdivisor<<1) <= x) 
        {
            tempdivisor<<=1;
            pow2<<=1;
        }
        ans += pow2;
        x = x - tempdivisor;
        // cout << "pow : " << pow2 << " ans : " << ans << endl;
    }
    
    if(signd) ans = (-1)*ans;
    if (ans > INT32_MAX) return INT32_MAX;
    if(ans < INT32_MIN) return INT32_MIN;
    return ans;
}
};