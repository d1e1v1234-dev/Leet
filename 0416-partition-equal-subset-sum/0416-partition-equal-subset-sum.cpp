class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum % 2==1) return false;
        sum/=2;
        vector<bool> dp(sum+1 , false);
        dp[0] = true;
        for(int x: nums)
        {
            for(int j=sum;j>=x;j--)
            {
                dp[j] = dp[j] || dp[j-x];
            }
        }
        return dp[sum];

    }
};