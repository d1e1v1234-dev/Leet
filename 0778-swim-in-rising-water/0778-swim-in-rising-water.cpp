class Solution {
public:
vector<pair<int,int>> dir = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
        > pq;    
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0];
            int i = curr[1];
            int j = curr[2];
            if(i == n-1 && j == n-1) return time;
            if(time > dist[i][j]) continue;

            for(auto d: dir)
            {
                int ni = i + d.first;
                int nj = j + d.second;

                if(ni >=n || ni <0 || nj >=n || nj<0) continue;

                int new_time = max(time,grid[ni][nj]);

                if(new_time < dist[ni][nj])
                {
                    dist[ni][nj] = new_time;
                    pq.push({new_time,ni,nj});
                }

            }
        }
        return -1;
    }
};