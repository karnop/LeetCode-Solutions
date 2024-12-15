class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0;
    int size = s.size();
    unordered_map<char, int> map;

    int ans = 0;
    while(right < size){
        if(map.find(s[right]) == map.end()) {
            ans = max(ans, right-left+1);
        }
        else {
            left = max(left, map[s[right]]+1); 
            ans = max(ans, right-left+1);
        }
        map[s[right]] = right;
        right++;
    }
    return ans;
}
};