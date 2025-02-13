class Solution {
public:
    bool helper(int n, int m, string &s, string &p, vector<vector<int>> &dp) {
        if(n == 0 && m == 0) return true;
        if(m == 0) return false;   
        if (n == 0) { 
            // s is empty, check if pattern consists only of '*'
            for (int i = 0; i < m; i++)
                if (p[i] != '*') return false;
            return true;
        } 
        if(dp[n][m] != -1) return dp[n][m];

        if(p[m-1] == '?' || p[m-1] == s[n-1]) {
            return dp[n][m] = helper(n-1, m-1, s, p, dp);
        }

        else if (p[m-1] == '*') {
            return dp[n][m] = (helper(n-1, m, s, p, dp) || helper(n, m-1, s, p, dp));
        }
        else {
            return dp[n][m] = false;
        }
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(n,m,s,p,dp);
    }
};