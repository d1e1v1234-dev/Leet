class DSU {
    public:
    vector<int>parent,rank;
    
    DSU(int n)
    {
        parent.resize(n);
        rank.assign(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i] =i;
        }   
    }
    int find(int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y)
    {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if(rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string,int> emailToAccount;
        for(int i=0;i<n;i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
                string email = accounts[i][j];

                if(emailToAccount.count(email))
                {
                    dsu.Union(i,emailToAccount[email]);
                }
                else
                {
                    emailToAccount[email] = i;
                }
            }
        }
        unordered_map<int,vector<string>> merged;
        for(auto& it : emailToAccount)
        {
            string email = it.first;
            int account = it.second;
            int root = dsu.find(account);
            merged[root].push_back(email);
        }
        vector<vector<string>> ans;
        for(auto& it : merged)
        {
            int root = it.first;
            vector<string> emails = it.second;
            sort(emails.begin(),emails.end());
            emails.insert(emails.begin(),accounts[root][0]);
            ans.push_back(emails);
        }
        return ans;

    }
};
