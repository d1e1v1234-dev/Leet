class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        vector<vector<int>> dp(m);    
        for(int i=0;i<m;i++)
        {
            dp[i].resize(i+1,0);
        }
        dp[0][0] = triangle[0][0];
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<dp[i].size();j++)
            {
                if(j==0)
                {
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if(j == dp[i].size()-1)
                {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else 
                {
                    dp[i][j] = min(dp[i-1][j] , dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans = min(ans,dp[m-1][i]);
        }
        return ans;
    }
};