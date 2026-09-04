class Solution {
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& visited, bool& reachPacific, bool& reachAtlantic) {
        visited[x][y] = true;

        if (x == 0 || y == 0) reachPacific = true;
        if (x == heights.size() - 1 || y == heights[0].size() - 1) reachAtlantic = true;

        if (reachPacific && reachAtlantic) return;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (auto& dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx >= 0 && nx < heights.size() && ny >= 0 && ny < heights[0].size()) {
                if (!visited[nx][ny] && heights[x][y] >= heights[nx][ny]) {
                    dfs(heights, nx, ny, visited, reachPacific, reachAtlantic);
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                bool reachPacific = false;
                bool reachAtlantic = false;
                
                dfs(heights, i, j, visited, reachPacific, reachAtlantic);
                
                if (reachPacific && reachAtlantic) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};