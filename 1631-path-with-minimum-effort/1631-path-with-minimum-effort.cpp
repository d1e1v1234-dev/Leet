class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m,vector<int> (n,INT_MAX));

        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});

        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,1,-1};
        while(!pq.empty())
        {
            int effort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(effort > dist[r][c]) continue;
            if(r==m-1 && c == n-1) return effort;
            for(int k=0;k<4;k++)
            {
                int nr = r+ dr[k];
                int nc = c+ dc[k];

                if(nr >=0 && nr<m && nc>=0 && nc<n)
                {
                    int edge_weight = abs(heights[nr][nc] - heights[r][c]);
                    int new_effort = max(effort ,edge_weight);
                    if(new_effort < dist[nr][nc])
                    {
                        dist[nr][nc] = new_effort;
                        pq.push({new_effort , {nr,nc}});
                    }
                }
            }
        }
        return 0;

    }
};
// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) 
//     {
//         return min(INT_MAX,dfs(0,0,heights,0,heights[0][0]));
//     }
//     vector<pair<int,int>> dir = {
//         {0,1},{1,0},{0,-1},{-1,0}
//     };
//     int dfs(int i , int j , vector<vector<int>> heights , int diff , int prev)
//     {
//         int m = heights.size();
//         int n = heights[0].size();
        
//         if(i == m-1 && j == n-1)
//         {
//             return diff;
//         }
//         heights[i][j] = -1;
//         int ans = INT_MAX;
//         for(auto d : dir)
//         {
//             int nx = i + d.first;
//             int ny = j + d.second;
//             if(nx < m && nx >=0 && ny < n && ny >=0 && heights[nx][ny] != -1)
//             {
//                 int new_diff = max(abs(heights[nx][ny] - prev),diff);
//                 int new_prev = heights[nx][ny];
//                 ans = min(ans,dfs(nx,ny,heights,new_diff,new_prev));
//             }
//         }
//         return ans;
//     }
// };