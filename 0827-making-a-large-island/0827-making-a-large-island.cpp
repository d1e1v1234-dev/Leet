class Solution {
public:
    vector<pair<int,int>> dir = {
            {1,0},
            {-1,0},
            {0,-1},
            {0,1}
        };
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int ans =0;
        vector<pair<int,int>> zeroes;
        unordered_map<int,int> colors;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0) zeroes.push_back({i,j});
            }
        }
        int color=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]== 1)
                {
                    grid[i][j] = color;
                    int count =1;
                    dfs(grid,i,j,count,color);
                    colors[color] =count;
                    color++;
                }
            }
        }
        if(zeroes.empty())
            return n * n;
        for(auto& it: zeroes)
        {
            int i = it.first;
            int j = it.second;
            int res = 0;
            unordered_set<int> s;
            
            for(auto d : dir)
            {
                int nx = i + d.first;
                int ny = j + d.second;
                if(nx>=0 && nx<n && ny>=0 && ny<n )
                {
                int v = grid[nx][ny];
                if(v == 0)continue;
                
                if(s.find(v) == s.end())
                {
                    s.insert(v);
                    res+=colors[v];
                }
                }
            }
            res++;
            ans = max(res,ans);
        }
        return ans;
    }

    
    void dfs(vector<vector<int>>& grid , int i , int j , int&count ,int& color )
    {
        int n = grid.size();
        for(auto d: dir)
        {
            int nx = i + d.first;
            int ny = j + d.second;

            if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]== 1)
            {
                count++;
                grid[nx][ny] =color;
                dfs(grid,nx,ny,count,color);
            }
        }
    }
};