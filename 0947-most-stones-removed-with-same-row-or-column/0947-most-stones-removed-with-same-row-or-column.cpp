class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();
        if(n<=1) return 0;
        vector<bool> vis(n,false);
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;

            ans +=  dfs(stones,vis,i,n);
        }
        return ans;
    }
    int dfs(vector<vector<int>>& stones,vector<bool>& vis , int idx , int& n)
    {
        vis[idx] = true;
        int ans =0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1]))
            {
                ans+= 1 + dfs(stones,vis,i,n);
            }
        }
        return ans;
    }
};