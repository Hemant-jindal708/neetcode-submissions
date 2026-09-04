class Solution {
    void dfs(vector<vector<char>>&grid,int x,int y)
    {
        if(grid[x][y]=='1')
        {
            grid[x][y]='x';
            if(x-1>=0) dfs(grid,x-1,y);
            if(x+1<grid.size()) dfs(grid,x+1,y);
            if(y-1>=0) dfs(grid,x,y-1);
            if(y+1<grid[0].size()) dfs(grid,x,y+1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    num++;
                    dfs(grid,i,j);
                }
            }
        }
        return num;
    }
};
