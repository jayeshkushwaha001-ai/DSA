#include <iostream>
#include <stack>
#include <string>

using namespace std;

// S -> REV S (CHANGE BRACKETS) -> POSTFIX S -> REV S -> ANS
class Solution
{
private:
    void rev(string &s)
    {
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
        {
            char temp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = temp;
        }
    }
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
    string infixToPrefix(string &s)
    {
        rev(s);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
                s[i] = '(';
            else if (s[i] == '(')
                s[i] = ')';
        }

        int i = 0;
        stack<char> st;
        string ans = "";
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
                while (!st.empty() &&
                       ((s[i] == '^' && priority(s[i]) <= priority(st.top())) ||
                        (s[i] != '^' && priority(s[i]) < priority(st.top()))))
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

        rev(ans);

        return ans;
    }
};