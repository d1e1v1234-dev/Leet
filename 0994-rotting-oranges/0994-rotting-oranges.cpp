class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0)
            return 0;

        int minutes = 0;

        vector<pair<int,int>> dir = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        while(!q.empty())
        {
            int sz = q.size();
            bool rotten = false;

            while(sz--)
            {
                auto [x,y] = q.front();
                q.pop();

                for(auto d : dir)
                {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if(nx>=0 && nx<n && ny>=0 && ny<m &&
                       grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        fresh--;
                        rotten=true;
                        q.push({nx,ny});
                    }
                }
            }

            if(rotten)
                minutes++;
        }

        return fresh==0 ? minutes : -1;
    }
};