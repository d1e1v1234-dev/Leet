class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[1],nums[0]);
        int prev1=0,prev2=0;
        for(int i=0;i< n-1;i++)    
        {
            int curr = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        int ans = prev1;
        prev1=0;
        prev2=0;
        for(int i=1;i<n;i++)    
        {
            int curr = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return max(ans,prev1);
            
    }
};