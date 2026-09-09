class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        vector<pair<int, int>> rotten;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) rotten.push_back({i, j});
            }
        }
        
        if (fresh == 0) return 0;
        
        vector<pair<int, int>> dr = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int mins = 0;
        
        while (!rotten.empty()) {
            vector<pair<int, int>> temp;
            for (auto [x, y] : rotten) {
                for (auto d : dr) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if (nx < 0 || nx == grid.size() || ny < 0 || ny == grid[0].size() || grid[nx][ny] != 1) {
                        continue;
                    }
                    
                    grid[nx][ny] = 2;
                    fresh--;
                    temp.push_back({nx, ny});
                }
            }
            
            if (!temp.empty()) {
                mins++;
            }
            rotten = temp;
        }
        
        return fresh == 0 ? mins : -1;
    }
};
