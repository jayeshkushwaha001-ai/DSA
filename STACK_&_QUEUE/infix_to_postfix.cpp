#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
private:
    int priority(char ch)
    {
        if (ch == '^')
        {
            return 3;
        }
        if (ch == '/' || ch == '*')
        {
            return 2;
        }
        if (ch == '+' || ch == '-')
        {
            return 1;
        }
        return -1;
    }

public:
    string infixToPostfix(string s)
    {
        string ans = "";
        stack<char> st;
        int i = 0;

        while (i < s.length())
        {
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' ||
                s[i] >= '0' && s[i] <= '9')
            {
                ans += s[i];
            }

            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (
                    !st.empty() &&
                    ((s[i] == '^' && priority(s[i]) < priority(st.top())) ||
                     (s[i] != '^' && priority(s[i]) <= priority(st.top()))))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};