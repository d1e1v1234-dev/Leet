class Solution {
public:
    int smallestIndex(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int c=0;
            int k = nums[i];
            while(k>0)
            {
                c+=k%10;
                k=k/10;
            }
            if(c == i)
                return i;
        }   
        return -1;
    }
};