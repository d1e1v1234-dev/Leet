class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1},
            {1,1},
            {-1,-1},
            {1,-1},
            {-1,1}
        };
        queue<pair<int,int>> q;
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        q.push({0,0});
        int ans =0;
        grid[0][0] = -1;
        while(!q.empty())
        {
            int k = q.size();
            ans++;
            while(k--)
            {
            auto [i,j] = q.front();
            q.pop();
            if(i== m-1 && j == n-1) return ans;
            
            for(auto d: dir)
            {
                int nx = i + d.first;
                int ny = j + d.second;

                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]== 0)
                {
                    q.push({nx,ny});
                    grid[nx][ny] = -1;
                }
            }
            }
        }
        return -1;
    }
};