class Solution {
    public int lengthOfLongestSubstring(String s) 
    {
        Set<Character> num = new HashSet<>();
        int maxLen = 0, left = 0;

        for(int i=0; i<s.length(); i++)
        {
            while(num.contains(s.charAt(i)))
            {
                num.remove(s.charAt(left));
                left++;
            }
                maxLen = Math.max(maxLen, i-left+1);
                num.add(s.charAt(i));
        }    
        return maxLen;
    }
}