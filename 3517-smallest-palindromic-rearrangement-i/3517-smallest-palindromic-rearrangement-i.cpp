class Solution {
public:
    string smallestPalindrome(string s) 
    {
        int n = s.size();
        vector<int> alphabet(26,0);
        for(int i=0;i<n;i++)
        {
            alphabet[s[i]-97]++;
        }
        string ans = "";
        int j=0;
        char ch = '\0';
        for(int i=0;i<26;i++)
        {
            if((alphabet[i]%2)!=0)
            {
                ch = i + 'a';
                alphabet[i]--;
            }
            if(alphabet[i]>0)
            {
                ans.insert(j,alphabet[i],i+'a');
                j+=(alphabet[i]/2);
            }
        }
        if(ch != NULL)
            ans.insert(j,1,ch);
        return ans;
    }
};