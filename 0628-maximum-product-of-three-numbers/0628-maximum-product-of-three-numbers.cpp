class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int n = nums.size();

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i]>max2)
            {
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i]>max3) max3 = nums[i];

            if(min1 > nums[i])
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if(min2 > nums[i])
            {
                min2 = nums[i];
            }
        }
        int ans1 = min1 * min2 * max1;
        int ans2 = max3 * max2 * max1;
        return max(ans1,ans2);

        // sort(nums.begin(),nums.end());
        // for(int x: nums) cout<<x<<",";
        // int ans =INT_MIN;
        // if(nums[0]<0 && nums[1]<0)
        // {
        //     if(nums[n-1]>=0)
        //     {
        //         ans = max(ans,(nums[0]*nums[1]*nums[n-1]));
        //     }
        //     else if(nums[n-1]<0)
        //     {
        //         ans = max(ans,(nums[n-1]*nums[n-2]*nums[n-3]));
        //     }
        // }
        // ans = max(ans,(nums[n-1]*nums[n-2]*nums[n-3]));
        // return ans;
    }
};