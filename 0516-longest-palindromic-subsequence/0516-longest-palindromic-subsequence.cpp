class Solution {
public:
    void lcs(string s1, string s2, vector<vector<int>> &dp) {
        for(int i=1; i<=s1.size(); i++) {
            for(int j=1; j<=s2.size(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
    }

    string constructString(string s1, string s2, vector<vector<int>> &dp) {
        int m = s1.size();
        int n = s2.size();

        string ans = "";
        while(m > 0 && n > 0) {
            if(s1[m-1] == s2[n-1]) {
                ans = s1[m-1] + ans;
                m--; n--;
            }

            else if (dp[m-1][n] > dp[m][n-1]) m--;
            else n--;
        }

        return ans;
    }


    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        lcs(s,s2,dp);
        string ans = constructString(s, s2, dp);
        return ans.size();
    }
};