class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>> &vis){
        if(row < 0 || row >= board.size() || col<0 || col >= board[0].size() || board[row][col] == 'X' || vis[row][col] == 1) return;

        vis[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            dfs(nrow, ncol, board, vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        // dfs on borders
        for(int i=0; i<rows; i++)   dfs(i, 0, board, vis); // cols 1
        for(int i=0; i<rows; i++)   dfs(i, cols-1, board, vis); // cols last
        for(int i=0; i<cols; i++)   dfs(0, i, board, vis); // cols 1
        for(int i=0; i<cols; i++)   dfs(rows-1, i, board, vis); // cols 1
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j] == 'O' && vis[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
};