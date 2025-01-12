class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // making a duplicate copy of data
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> data = grid;

        int freshOranges = 0;
        // {{r,c}, t}
        queue<pair<pair<int, int>, int>>q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int val = grid[i][j];
                data[i][j] = val;
                if(val == 1) freshOranges++;
                if(val == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        // queue logic
        int maxtime = 0;
        int queCnt = 0;

        while(!q.empty()){
            auto elem = q.front();
            int r = elem.first.first;
            int c = elem.first.second;
            int t = elem.second;
            q.pop();

            maxtime = max(maxtime, t);

            // insertions
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];

                if(nrow >=0 && nrow < rows && ncol >= 0 && ncol < cols && data[nrow][ncol] == 1 ){
                    data[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t+1});
                    queCnt++;
                }   
            }
        }

        if(queCnt != freshOranges) return -1;
        return maxtime;

    }
};