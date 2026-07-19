class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i] == -1)
            {
                color[i] = 0;
                if(!dfs(i,graph,color)) return false;
            }   
        }
        return true;
    }
    bool dfs(int i , vector<vector<int>>& graph, vector<int>& color)
    {
        for(int adj : graph[i])
        {
            if(color[adj] == -1)
            {
                color[adj] = 1 - color[i];
                if(!dfs(adj,graph,color))
                {
                    return false;
                }
            }
            else if(color[adj] == color[i]) return false;
        }
        return true;
    }
};