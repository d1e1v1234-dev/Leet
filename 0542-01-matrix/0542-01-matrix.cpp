class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<tuple<int,int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j,0});
                }
            }
        }
        vector<pair<int,int>> dir = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };
        while(!q.empty())
        {
            auto [i,j,k] = q.front();
            q.pop();
            if(vis[i][j]) continue;
            vis[i][j]=1;
            dis[i][j]=k;
            for(auto d : dir)
                {
                    int nx = i + d.first;
                    int ny = j + d.second;

                    if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny])
                    {
                        q.push({nx,ny,k+1});
                    }
                }
        }
        return dis;
    }
};