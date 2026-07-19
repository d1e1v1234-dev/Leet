class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> ter(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(graph[i].empty()) ter[i] =1;
        }    
        vector<bool> ch(n,false);
        bool changed = true;
        while(changed)
        {
        changed = false;
        for(int i=0;i<n;i++)
        {
            if(ch[i]) continue;
            bool ok = true;
            for(int adj : graph[i])
            {
                if(ter[adj] == 0)
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                ans.push_back(i);
                ter[i] = 1;
                ch[i] = true;
                changed = true;
            } 
            
        }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};