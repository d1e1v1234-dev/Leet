class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int prev1=0,prev2=0;
        for(int x: nums)    
        {
            int curr = max(prev1,prev2+x);
            prev2 = prev1;
            prev1 = curr;
        }
        return max(prev1,prev2);
    }
};
// class Solution {
// public:
//     int rob(vector<int>& nums) 
//     {
//         int n = nums.size();
//         if(n==1) return nums[0];
//         if(n==2) return max(nums[1],nums[0]);
//         if(n==3) return max(nums[0] + nums[2],nums[1]);
//         vector<int> dp(n);
//         dp[0] = nums[0];
//         dp[1] = nums[1];
//         dp[2] = nums[0]+nums[2];
//         for(int i = 3 ; i<n;i++)
//         {
//             dp[i] = max(dp[i-2],dp[i-3]) + nums[i];
//         }
//         return max(dp[n-1],dp[n-2]);
//     }
// };