class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int mod = m*n;
        k = k% mod;
        while(k--)
        {
            int st = grid[0][0];
            int prev = grid[m-1][n-1];
            int temp =0;
            for(int i =0 ;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    temp = grid[i][j];
                    grid[i][j] = prev;
                    prev = temp;
                }
            }
        }   
        return grid;
    }
};