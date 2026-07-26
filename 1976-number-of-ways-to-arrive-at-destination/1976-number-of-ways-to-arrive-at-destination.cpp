class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        int m = roads.size();
        int MOD = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++)
        {
            adj[roads[i][0]].push_back({roads[i][2],roads[i][1]});
            adj[roads[i][1]].push_back({roads[i][2],roads[i][0]});
        }
        vector<long long> dist(n,LLONG_MAX);       
        vector<int> ways(n,0);       
        priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
        > pq;
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty())
        {
            int node = pq.top().second;
            long long cost = pq.top().first;
            pq.pop();
            if(cost > dist[node]) continue;
            for(auto x : adj[node])
            {
                long long new_cost = cost + x.first;
                if(new_cost < dist[x.second]) 
                {
                dist[x.second] = new_cost;
                ways[x.second] = ways[node];
                pq.push({new_cost,x.second});
                }
                else if(new_cost == dist[x.second])
                {
                    ways[x.second] = (ways[x.second] + ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
        
    }
};