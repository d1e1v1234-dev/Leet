class Solution {
public:
vector<pair<int,int>> dir = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1) dfs(grid,0,i,n,m);
        }
        for(int i=1;i<n;i++)
        {
            if(grid[i][0]==1) dfs(grid,i,0,n,m);
        }
        for(int i=1;i<m;i++)
        {
            if(grid[n-1][i]==1) dfs(grid,n-1,i,n,m);
        }
        for(int i=1;i<n-1;i++)
        {
            if(grid[i][m-1]==1) dfs(grid,i,m-1,n,m);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid , int i , int j,int& n , int& m)
    {
        grid[i][j] = 0;
        for(auto d: dir)
        {
            int nx = i + d.first;
            int ny = j + d.second;

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]== 1)
            {
                dfs(grid,nx,ny,n,m);
            }
        }
    }
};