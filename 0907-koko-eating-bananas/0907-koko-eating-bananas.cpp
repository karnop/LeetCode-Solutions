class Solution {
public:
    int check(vector<int>& piles, int mid, int h){
    long long cnt = 0;
    for(int i=0; i<piles.size(); i++){
        cnt+= ceil((double)piles[i]/mid);
        if(cnt > h) return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = 1;
    for (int i=0; i<piles.size(); i++) high = max(high, piles[i]);

    int ans = INT32_MAX;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(check(piles, mid, h)){
            ans = min(ans, mid);
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

};