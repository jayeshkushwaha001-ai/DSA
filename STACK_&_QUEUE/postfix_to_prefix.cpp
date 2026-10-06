#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    string postToPre(string s) {
        int i = 0;
        stack<string> st;
        string ans;
        while (i < s.length()) {
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' ||
                s[i] >= '0' && s[i] <= '9') {
                st.push(string(1, s[i]));
            } else {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                ans = s[i] + s2 + s1;
                st.push(ans);
            }
            i++;
        }
        return st.top();
    }
};