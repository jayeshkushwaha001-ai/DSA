#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    string prefixToPostfix(const string& s) {
        int i = s.length()-1;
        stack<string> st;
        string ans;
        while (i>=0) {
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' ||
                s[i] >= '0' && s[i] <= '9') {
                st.push(string(1, s[i]));
            } else {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                ans = s1 + s2 + s[i];
                st.push(ans);
            }
            i--;
        }
        return st.top();
    }
};