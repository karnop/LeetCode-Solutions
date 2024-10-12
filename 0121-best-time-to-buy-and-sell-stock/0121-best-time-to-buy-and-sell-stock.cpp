class Solution {
public:
    int maxProfit(vector<int>& price) {
    
    int len = price.size();
    int profit = 0;
    int curr = price[0];

    for(int i=1; i<len; i++)
    {
        if(price[i] > curr)
        {
            profit = max(profit, (price[i] - curr));
        }
        else if(price[i] < curr) 
        {
            curr = price[i];
        }
    }   
    return profit;
    }
};