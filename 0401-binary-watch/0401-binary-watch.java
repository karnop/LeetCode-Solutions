class Solution {

    int hour[] = {1, 2, 4 ,8}; 
    int minutes[] = {1, 2, 4, 8, 16, 32};
    
    public void helper(int idx, int hsum, int msum, int countMax, List<String> res)
    {
        if(countMax == 0)
        {
            final String ans = Integer.toString(hsum) + (msum < 10 ? ":0" : ":") + Integer.toString(msum);
            res.add(ans);
            return;
        }

        for(int i=idx; i<hour.length+minutes.length; ++i)  
        {
            if(i < 4 && hsum+hour[i] < 12)
                helper(i+1, hsum+hour[i], msum, countMax-1, res);
            else if(i >= 4 && msum+minutes[i-4] < 60)  
                helper(i+1, hsum, msum+minutes[i-4], countMax-1, res);
        }


    }
    
    public List<String> readBinaryWatch(int turnedOn) 
    {
        List<String> res = new ArrayList<>();
        if(turnedOn >8) return res;

        helper(0, 0, 0, turnedOn, res);
        return res;
    } 
}