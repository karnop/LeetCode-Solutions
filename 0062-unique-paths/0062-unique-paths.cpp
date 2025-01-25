class Solution {
public:
    long long int helper(int m, int n, vector<vector<int>> &dp) {
        if(m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];

        long long int up = 0, left = 0;
        up = helper(m-1, n, dp);
        left = helper(m, n-1, dp);

        return dp[m][n] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, dp);
    }
};