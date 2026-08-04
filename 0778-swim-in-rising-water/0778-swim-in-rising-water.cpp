class DSU{
    public:
    vector<int> parent,size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if(parent[x] == x ) return x;
        return parent[x] = find(parent[x]);

    }
    void unite(int i,int j)
    {
        int pi = find(i);
        int pj = find(j);
        if(pi == pj) return; 
        if(size[pi]<size[pj]) swap(pi,pj);

        parent[pj] = pi;

        size[pi]+=size[pj];
    }

};
class Solution {
public:
    vector<pair<int,int>> dir = {
        {0,-1},
        {0,1},
        {-1,0},
        {1,0}
    };
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        vector<vector<int>> cells;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cells.push_back({grid[i][j],i,j});
            }
        }

        sort(cells.begin(),cells.end());

        DSU dsu(n*n);
        vector<vector<bool>> active(n,vector<bool>(n,false));
        for(auto& cell : cells)
        {
            int h = cell[0];
            int i = cell[1];
            int j = cell[2];
            int id = i * n + j;
            active[i][j] = true;

            for(auto d:dir)
            {
                int ni = i + d.first;
                int nj = j + d.second;
                if(ni >=0 && ni < n && nj>=0 && nj<n && active[ni][nj])
                {
                    int nid = ni * n + nj;
                    dsu.unite(id,nid);
                }
            }
            if(dsu.find(0) == dsu.find(n * n-1))
            {
                return h;
            }
        }

        return -1;
    }
};

// class Solution {
// public:
// vector<pair<int,int>> dir = {
//         {1,0},
//         {-1,0},
//         {0,1},
//         {0,-1}
//     };

//     int swimInWater(vector<vector<int>>& grid) 
//     {
//         int n = grid.size();
//         priority_queue<
//         vector<int>,
//         vector<vector<int>>,
//         greater<vector<int>>
//         > pq;    
//         vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
//         dist[0][0]=grid[0][0];
//         pq.push({grid[0][0],0,0});
//         while(!pq.empty())
//         {
//             auto curr = pq.top();
//             pq.pop();
//             int time = curr[0];
//             int i = curr[1];
//             int j = curr[2];
//             if(i == n-1 && j == n-1) return time;
//             if(time > dist[i][j]) continue;

//             for(auto d: dir)
//             {
//                 int ni = i + d.first;
//                 int nj = j + d.second;

//                 if(ni >=n || ni <0 || nj >=n || nj<0) continue;

//                 int new_time = max(time,grid[ni][nj]);

//                 if(new_time < dist[ni][nj])
//                 {
//                     dist[ni][nj] = new_time;
//                     pq.push({new_time,ni,nj});
//                 }

//             }
//         }
//         return -1;
//     }
// };