class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int curr = nums[0];
        vector<int> ans;
        for(int i =1;i<n;i++)
        {
            while(++curr < nums[i])
            {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};