class Solution {
public:

    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) {
            return dp[i][j] = helper(i-1, j-1, s, t, dp) + helper(i-1, j, s, t, dp);
        }
        else {
            return dp[i][j] = helper(i-1, j, s, t, dp);
        }
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        helper(n, m, s, t, dp);
        return dp[n][m];
    }
};