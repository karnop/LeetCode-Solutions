class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n); 
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // dijkstra
        while(!q.empty()) {
            auto [stops, x] = q.front();
            int node = x.first;
            int cost = x.second;
            q.pop();

            if(stops > k) continue;
            for(auto nbors : adj[node]) {
                int adjNode = nbors.first;
                int wt = nbors.second;

                if(cost + wt < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost+wt;
                    q.push({stops+1, {adjNode, cost+wt}});
                }
            }

        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];

    }
};