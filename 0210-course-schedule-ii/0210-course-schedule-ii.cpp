class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n = numCourses;
        vector<vector<int>> adjlst(n);
        vector<int> indegree(n,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adjlst[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int vis=0;
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            vis++;
            for(auto adjnode : adjlst[node])
            {
                indegree[adjnode]--;
                if(indegree[adjnode]==0)
                {
                    q.push(adjnode);
                }
            }
        }
        return (vis==n) ? ans : vector<int>{};    
    }
};