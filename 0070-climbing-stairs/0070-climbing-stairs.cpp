class Solution {
public:
    int helper(int n, vector<int> & ans) {
        if(ans[n] != -1) return ans[n];
        if(n == 0 || n == 1) {
            ans[n] = 1;
            return 1;
        }
        ans[n] = helper(n-1, ans) + helper(n-2, ans);
        return ans[n];
    }   
    int climbStairs(int n) {
        vector<int> ans(n+1, -1);
        return helper(n, ans);
    }
};