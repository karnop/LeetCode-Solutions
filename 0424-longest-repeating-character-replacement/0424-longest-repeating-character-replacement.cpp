class Solution {
public:
    int characterReplacement(string s, int k) {
    int left = 0;
    int ans = 0;
    map<int, int> um;
    int maxf = 0;
    
    for(int right=0; right<s.size(); right++)
    {
        um[s[right] - 'A']++;

        maxf = max(maxf, um[s[right] - 'A']);

        while((right-left+1) - maxf > k)
        {
            um[s[left] - 'A']--;
            maxf = 0;
            for(auto x : um){
                maxf = max(maxf, x.second);
            }           
            left++;
        }
        ans = max(ans, right-left+1);
    }
    return ans;
}
};