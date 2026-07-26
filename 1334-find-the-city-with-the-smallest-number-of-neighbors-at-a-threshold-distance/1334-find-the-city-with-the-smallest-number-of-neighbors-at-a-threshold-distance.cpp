class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        int m = edges.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }
        int ans = INT_MAX;
        int ans_i = 0;
        for(int i=0;i<n;i++)
        {
        vector<int> dist(n,INT_MAX);       
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > pq;
        pq.push({0,i});
        dist[i] = 0;
        while(!pq.empty())
        {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if(cost > dist[node]) continue;
            for(auto x : adj[node])
            {
                int new_cost = cost + x.first;
                if(new_cost >= dist[x.second]) continue;
                dist[x.second] = new_cost;
                pq.push({new_cost,x.second});
            }
        }
        int ans_temp =0;
        for(int j=0;j<n;j++)
        {
            if(dist[j] <= distanceThreshold ) ans_temp++;
        }
        if(ans_temp <= ans)
        {
            ans = ans_temp;
            ans_i =i;
        }
        }
        return ans_i;
    }
};