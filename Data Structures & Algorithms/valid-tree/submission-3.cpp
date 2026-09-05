class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        
        if (n == 1) return true;

        vector<vector<int>> adjList(n);
        vector<int> degree(n, 0);
        
        for (auto& e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        int processedNodes = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processedNodes++;
            
            for (int neighbor : adjList[node]) {
                degree[neighbor]--;
                if (degree[neighbor] == 1) {
                    q.push(neighbor);
                }
            }
        }
        
        return processedNodes == n;
    }
};