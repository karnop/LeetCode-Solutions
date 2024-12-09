class Solution {
public:
    bool checkParenthesis(int i, string temp, stack<char> &s)
{
    if(i == temp.size())
    {
        if(s.empty() == true) return true;
        return false;
    }
    int elem = temp[i];
    if(!s.empty() && (elem == ')' && s.top() == '(')) s.pop();
    else s.push(temp[i]);
    return checkParenthesis(i+1, temp, s);
}

void generateParenthesiss(int k, int left, int right, string temp, vector<string>&ans)
{
    if(temp.size() == k)
    {
        stack<char> s;
        if(checkParenthesis(0,temp,s))
            ans.push_back(temp);
        return;
    }

    if(left!=0) generateParenthesiss(k, left-1, right, temp+'(', ans);
    if(right!=0) generateParenthesiss(k, left, right-1, temp+')', ans);
}

    vector<string> generateParenthesis(int n) {
    string temp;
    vector<string> ans;
    int k = n;

    generateParenthesiss(2*k, k, k, temp, ans);
    return ans;
    }
};