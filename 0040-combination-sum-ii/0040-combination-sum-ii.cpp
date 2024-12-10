class Solution {
public:
void helper(int index, int sum, vector<int> &temp, vector<int> &candidates, int target, vector<vector<int>> &ans) {
    if (sum == target) {
        ans.push_back(temp);
        return;
    }
    if (sum > target || index == candidates.size()) return;

    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1]) continue;

        temp.push_back(candidates[i]);
        helper(i + 1, sum + candidates[i], temp, candidates, target, ans);
        temp.pop_back(); 
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;

    sort(candidates.begin(), candidates.end());
    helper(0, 0, temp, candidates, target, ans);
    return ans;
}

};