class Solution {
public:
    string reverseParentheses(string s) 
    {
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i] != ')')
            {
                st.push(s[i]);
            }
            else
            {
                string k = "";
                while(st.top() != '(')
                {
                    k+=st.top();
                    st.pop();
                }
                st.pop();
                for(char c : k)
                    st.push(c);
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};