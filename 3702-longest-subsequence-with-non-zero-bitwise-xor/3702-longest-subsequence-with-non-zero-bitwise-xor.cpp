class Solution {
public:
    int longestSubsequence(vector<int>& nums) 
    {
        int n = nums.size();
        
        int total =0;
        bool hasnotzero = false;
        for(int x: nums)
        {
            total ^= x;

            if(x !=0)
            {
                hasnotzero = true;
            }
        }
        if(total !=0)
        {
            return n;
        }

        if(hasnotzero)
        {
            return n-1;
        }
        return 0;
    }
};