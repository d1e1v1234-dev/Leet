class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }    
        // dist[node][edgesUsed]
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        // {cost, node, edgesUsed}
        priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
        > pq;

        dist[src][0] =0;
        pq.push({0,src,0});

        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int node = curr[1];
            int edges = curr[2];

            if(node == dst) return cost;
            if(edges == k+1  || cost > dist[node][edges]) continue;

            for(auto &it : adj[node])
            {
                int next = it.first;
                int wt = it.second;

                int new_cost = cost+wt;
                if(new_cost < dist[next][edges+1])
                {
                    dist[next][edges+1] = new_cost;
                    pq.push({new_cost,next,edges+1});
                }
            }
        }
        return -1;
    }
};