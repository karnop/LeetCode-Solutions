class Solution {
public:
    void helper(int x, int k, int n, vector<int> temp, vector<vector<int>> &ans)
{
    if(temp.size() == k)
    {
        if(n == 0) ans.push_back(temp);
        return;
    }
    if(x > 9) return;
    temp.push_back(x);
    helper(x+1, k, n-x, temp, ans);
    temp.pop_back();
    helper(x+1, k, n, temp, ans);
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    helper(1, k, n, temp, ans);
    return ans;
}



};