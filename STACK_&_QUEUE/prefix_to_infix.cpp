#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    string prefixToInfix(string s) {
        int i = s.length()-1;
        string ans = "";
        stack<string> st;
        while (i>=0) {
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' ||
                s[i] >= '0' && s[i] <= '9') {
                st.push(string(1, s[i]));
            } else {
                string ch1 = st.top();
                st.pop();
                string ch2 = st.top();
                st.pop();
                ans = '(' + ch1 + s[i] + ch2 + ')';
                st.push(ans);
            }
            i--;
        }
        return st.top();
    }
};