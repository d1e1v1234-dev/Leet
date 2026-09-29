class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;
    bool hasValidPath(vector<vector<char>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(m+n , -1)));
        return dfs(0,0,0,grid);    
    }
    bool dfs (int i , int j , int score , vector<vector<char>>& grid)
    {
        if(grid[i][j] == '(') score++;
        else score--;
        if(score <0) return false;
        bool ans = false;
        if(i == m-1 && j == n-1)
        {
            return score == 0;
        }
        if(dp[i][j][score] != -1)
        {
            return dp[i][j][score];
        }
        if(i<m-1)
        {
            ans = ans || dfs(i+1,j,score,grid);
        }
        if(j<n-1)
        {
            ans = ans || dfs(i,j+1,score,grid);
        }
        dp[i][j][score] = ans;
        return ans;
    }
};