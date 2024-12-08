class Solution {
public:
    string fine(string s)
{
    string result;
    for (int i = 0; i < s.size(); i++) {
        if (isalnum(s[i])) { // Check if the character is alphabetic
            if (isupper(s[i])) {
                result += tolower(s[i]); // Convert to lowercase and add to result
            } else {
                result += s[i]; // Add lowercase characters as is
            }
        }
    }
    return result;
}
    bool check(string s, int i, int j)
    {
        if(i>= j) return true;
        return (s[i] == s[j]) && check(s, i+1, j-1);
    }
    bool isPalindrome(string s) {
        s = fine(s);
        int i = 0, j=s.size()-1;
        while(true)
        {
            if(i>= j) return true;
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
        
    }
};