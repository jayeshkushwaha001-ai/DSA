#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.length(); i++) {
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        if (st.empty())
            return "0";

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (ans.length() != 0 && ans[i] == '0') {
            i++;
        }
        string final = ans.substr(i);

        return final.empty() ? "0" : final;
    }
};