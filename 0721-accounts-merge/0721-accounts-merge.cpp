class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size();
        vector<bool> vis(n,false);
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            set<string> s;
            dfs(accounts,vis,i,n,s);
            vector<string> v;
            v.push_back(accounts[i][0]);
            for(auto& email : s)
            {
                v.push_back(email);
            }
            ans.push_back(v);
        }
        return ans;
    }
    void dfs(vector<vector<string>>& accounts,vector<bool>& vis , int idx ,int& n , set<string>& s )
    {
        vis[idx] =true;
        for(int i=1;i<accounts[idx].size();i++)
        {
            s.insert(accounts[idx][i]);
        }
        for(int i=0;i<n;i++)
        {
            bool found = false;
            int x = accounts[i].size();
            if(!vis[i] && accounts[i][0] == accounts[idx][0] )
            {
                
                for(int k=1;k<x;k++)
                {
                    if(s.find(accounts[i][k]) != s.end()) found = true;
                    if(found) break;
                }
            }
            if(found)
            {
                vis[i]=true;
                for(int k=1;k<x;k++)
                {
                    s.insert(accounts[i][k]);
                }
                dfs(accounts,vis,i,n,s);
            }
        }
    }
};