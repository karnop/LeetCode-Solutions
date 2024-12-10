class Solution {
public:
    bool helper(int i, int j, int index, string& word, vector<vector<char>>& board, vector<vector<int>>& vis) {
    // Base cases
    if (index == word.size()) return true; // All characters matched
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false; // Out of bounds
    if (vis[i][j] || board[i][j] != word[index]) return false; // Already visited or mismatch

    // Mark as visited
    vis[i][j] = 1;

    // Explore all directions
    bool found = helper(i, j - 1, index + 1, word, board, vis) || // Left
                 helper(i + 1, j, index + 1, word, board, vis) || // Down
                 helper(i, j + 1, index + 1, word, board, vis) || // Right
                 helper(i - 1, j, index + 1, word, board, vis);   // Up

    // Backtrack
    vis[i][j] = 0;

    return found;
}
bool exist(vector<vector<char>>& board, string word) {
    string temp;
    vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));

    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[0].size(); j++)
        {
            if (helper(i, j, 0, word, board, vis)) { 
                return true;
            }
        }
    }   

    return false;
}

};