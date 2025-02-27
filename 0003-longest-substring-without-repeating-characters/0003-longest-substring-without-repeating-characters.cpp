class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int ans = 0;
        unordered_map<char, int> map;

        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            // character in map
            while (map.count(ch) != 0) {
            map.erase(s[left]); 
            left++;
            }

            // not in map
            map[s[i]] = 1;
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};