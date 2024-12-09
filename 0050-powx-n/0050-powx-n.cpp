class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
    if(n == 1) return x;
    if(n == -1) return 1/x;
    double res = myPow(x, floor(n/2));
    res = res*res;
    if(n%2 == 1 || n%2 == -1) {
        if(n > 0) res*=x;
        else if(n < 0) res*=(1/x);
    }
    return res;
}
};