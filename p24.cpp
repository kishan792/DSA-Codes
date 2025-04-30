#include<iostream>
#include<stack>
using namespace std;
 int getPriority(char op)
    {
        if(op=='^')
        {
            return 3;
        }
        else if(op=='*' || op=='/')
        {
            return 2;
        }
        else if(op=='+' || op=='-')
        {
            return 1;
        }
        else{
            return 0;
        }
        return 0;
    }

    string reverseString(string s)
    {
        int i = 0;
        int j = s.size()-1;
        while(i<=j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
    }
    
    string convertToPrefix(string& s)
     {   
        stack<char> st;
        string ans = "";
        
         s = reverseString(s);

        for(int i = 0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                s[i] =')';
            }
            else if(s[i]==')')
            {
                s[i] = '(';
            }
        }

        for(int i = 0;i<s.size();i++)
        {
            if((s[i]>='A'&&s[i]<='Z') || (s[i]>='a'&&s[i]<='z') || (s[i]>='0'&&s[i]<='9'))
            {
                ans+=s[i];
            }
            else if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                while(st.empty()!=true && st.top()!='(')
                {
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                if(s[i]=='^')
                {
                    while(st.empty()!=true && getPriority(s[i])<=getPriority(st.top()))
                    {
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(s[i]); 
                }
                else{
                    while(st.empty()!=true && getPriority(s[i])<getPriority(st.top()))
                    {
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        
        while(st.empty()!=true)
        {
            ans+=st.top();
            st.pop();
        }
        
        ans = reverseString(ans);
        return ans;
     }
int main() 
{
    string s = "(a-b/c)*(a/k-l)";
    cout << convertToPrefix(s) << endl;
    return 0;
}
//(a-b/c)*(a/k-l)