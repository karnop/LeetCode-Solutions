class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // making adjacency list
        vector<vector<int>> adj(numCourses, vector<int>(0));
        for(auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        // Topo sort
        vector<int> inDegree(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            for(auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        vector<int> topo;
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(inDegree[i] == 0) 
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) 
                    q.push(it);
            }
        }

        if(topo.size() == numCourses) return true;
        return false;
    }
};