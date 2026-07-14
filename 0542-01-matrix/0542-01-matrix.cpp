class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dis[i][j] =0;
                    q.push({i,j});
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
            auto [i,j] = q.front();
            q.pop();
            
            for(auto d : dir)
                {
                    int nx = i + d.first;
                    int ny = j + d.second;

                    if(nx>=0 && nx<n && ny>=0 && ny<m && (dis[nx][ny] == -1))
                    {
                        dis[nx][ny] = dis[i][j]+1;
                        q.push({nx,ny});
                    }
                }
        }
        return dis;
    }
};