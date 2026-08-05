class Solution {
public:
    
    int climbStairs(int n) 
    {
        if(n==1 || n ==2)return n;
        vector<int> val(n+1,-1);
        val[1] = 1; 
        val[2] = 2; 
        return climb(n-1,val) + climb(n-2,val);    
    }
    int climb(int n , vector<int>& val)
    {
        if(n==1 || n ==2)return n;
        if(val[n] != -1 ) return val[n];
        val[n] = climb(n-1,val) + climb(n-2,val); 
        return val[n];
    }
};