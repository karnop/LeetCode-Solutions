class Solution {
public:
    bool checkPalindrome(int i, int j, string s){
        if(i >= j) return true;
        return ((s[i] == s[j] ) && checkPalindrome(i+1, j-1, s));
    }
    string bruteForce(string s) {
        // chrcking all possible strings
        string ans = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++) {
                string temp = s.substr(i, j-i+1);
                if(checkPalindrome(0, temp.size()-1, temp) && temp.size() > ans.size()) ans = temp;
            }
        }
        return ans;
    }

    string expandingAroundCenter(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++) {
            // odd len
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r-l+1 > ans.size()) {
                    ans = s.substr(l, r-l+1);
                }
                l--; r++;
            }

            // even len
            l = i, r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r-l+1 > ans.size()) {
                    ans = s.substr(l, r-l+1);
                }
                l--; r++;
            }
        }
        return ans;
    }
    string longestPalindrome(string s) {
        return bruteForce(s); // O(n^3)
        return expandingAroundCenter(s); // O(n^2)

    }
};