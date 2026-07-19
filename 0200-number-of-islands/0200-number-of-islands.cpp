class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> cord;
        int ans =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]== '1')
                {
                    cord.push_back({i,j});
                }
            }
        }    
        vector<vector<int>> vis( m,vector<int>(n,0));
        for(int i=0;i<cord.size();i++)
        {
            int x = cord[i].first;
            int y = cord[i].second;
            if(vis[x][y]) continue;
            ans++;
            vis[x][y] = 1;
            dfs(grid,x,y,vis);
        }
        return ans;
    }
    vector<pair<int,int>> dir = {
        {1,0},
        {-1,0},
        {0,-1},
        {0,1}
    };
    void dfs(vector<vector<char>>& grid , int i , int j , vector<vector<int>>& vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        for(auto d: dir)
        {
            int nx = i + d.first;
            int ny = j + d.second;

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]== '1' && vis[nx][ny] == 0)
            {
                vis[nx][ny] =1;
                dfs(grid,nx,ny,vis);
            }
        }
    }
};