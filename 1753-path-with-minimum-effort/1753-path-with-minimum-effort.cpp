class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // priority queue
        priority_queue<pair<int , pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        dist[0][0] = 0;

        pq.push({0, {0,0}});
        while(!pq.empty()) {
            auto [effort, coords] = pq.top();
            int r = coords.first, c = coords.second;
            pq.pop();

            if(r == rows-1 && c == cols-1) return effort;

            // neighbors
            for(auto [dr, dc] : directions) {
                int nr = dr+r , nc = dc+c;

                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols) {
                    // Calculate the new effort for this neighbor
                    int newEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));

                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};