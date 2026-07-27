class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int m = connections.size();
        if(m < n-1) return -1;
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }    
        int ans =0;
        int viss=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            ans++;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                if(vis[node]) continue;
                vis[node] =1;
                viss++;
                for(int& x : adj[node])
                {
                    if(!vis[x])
                    {
                        q.push(x);
                    }
                }
            }
            if(viss == n) break;
        }
        return ans-1;
    }
};