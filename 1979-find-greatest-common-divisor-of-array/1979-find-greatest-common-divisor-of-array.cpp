class Solution {
public:
    int findGCD(vector<int>& nums) 
    {
        int n = nums.size();
        int minn = nums[0];    
        int maxx = nums[0];    
        for(int i=0;i<n;i++)
        {
            minn = min(minn,nums[i]);
            maxx = max(maxx,nums[i]);
        }
        int ans =1;
        for(int i=1;i<=minn;i++)
        {
            if((maxx % i )==0 && (minn % i ) ==0) ans = i;
        }
        return ans;
    }
};