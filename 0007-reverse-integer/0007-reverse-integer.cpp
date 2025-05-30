class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            int lastDigit = x%10;
            x = x/10;
            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && lastDigit > 7))
                return 0;
            if (ans < INT_MIN/10 || (ans == INT_MIN/10 && lastDigit < -8))
                return 0;   
            ans = ans*10;
            ans += lastDigit;
        }
        return ans;
    }
};