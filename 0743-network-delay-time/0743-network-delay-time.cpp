class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        int m = times.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<m;i++)
        {
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }
        vector<int> dist(n+1,INT_MAX);       
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > pq;
        pq.push({0,k});
        dist[k] = 0;
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
        int ans =0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]== INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};