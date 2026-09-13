class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<long long>> dp(n1+1 , vector<long long>(n2+1,0));
        for(int i=0 ; i<=n1;i++)
        {
            dp[i][0] = 1;
        }
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    if(dp[i-1][j] > INT_MAX - dp[i-1][j-1])
                        dp[i][j] = INT_MAX;
                    else
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n1][n2];
    }
};