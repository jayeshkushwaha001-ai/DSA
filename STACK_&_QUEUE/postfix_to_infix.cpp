#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    string postToInfix(string postExp)
    {
        int i = 0;
        stack<string> st;
        string ans;
        while (i < postExp.length())
        {
            if (postExp[i] >= 'A' && postExp[i] <= 'Z' ||
                postExp[i] >= 'a' && postExp[i] <= 'z' ||
                postExp[i] >= '0' && postExp[i] <= '9')
            {
                st.push(string(1, postExp[i]));
            }
            else
            {
                string ch1 = st.top();
                st.pop();
                string ch2 = st.top();
                st.pop();
                ans = '(' + ch2 + postExp[i] + ch1 + ')';
                st.push(ans);
            }
            i++;
        }
        return st.top();
    }
};
