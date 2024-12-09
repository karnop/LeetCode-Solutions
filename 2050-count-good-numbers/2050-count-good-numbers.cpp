class Solution {
public:
  long long exp(long long x, long long y) {
    int mod = 1e9 + 7;
    if (y == 0) return 1LL; 
    long long res = exp(x, y / 2) % mod;
    res = (res * res) % mod; // Ensure result stays within modulo
    if (y % 2 == 1) res = (res * x) % mod; // Handle odd exponents
    return res;
}

int countGoodNumbers(long long n) {
    if(n == 1) return 5;
    long long odd = n/2;
    long long even = (n+1)/2;

    long long odd_res = exp(4, odd);
    long long even_res = exp(5, even);

    int mod = 1e9 + 7;
    int res = ((odd_res%mod) * (even_res%mod)%mod);
    return res;
}

};