class Solution {
    int dfs(vector<vector<int>>&grid,int x,int y)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]!=1) return 0;
        grid[x][y]=-1;
        return 1 + dfs(grid,x+1,y) + dfs(grid,x-1,y) + dfs(grid,x,y+1) + dfs(grid,x,y-1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1) maxArea=max(maxArea,dfs(grid,i,j));
            }
        }
        return maxArea;
    }
};