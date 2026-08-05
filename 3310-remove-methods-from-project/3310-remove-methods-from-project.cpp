class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) 
    {
        int m = invocations.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++)
        {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }    
        queue<int> q;
        q.push(k);
        vector<int> vis(n,0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            for(int& x: adj[node])
            {
                q.push(x);
            }
        }
        bool found = false;
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            for(int& x: adj[i])
            {
                if(vis[x]) 
                {
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        vector<int> ans;
        if(found)
        {
            for(int i=0;i<n;i++)
            {
                ans.push_back(i);
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(!vis[i]) ans.push_back(i);
            }
        }
        return ans;
    }
};