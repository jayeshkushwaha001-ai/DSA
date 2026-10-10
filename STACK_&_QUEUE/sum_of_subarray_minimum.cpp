#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long mod = 1e9 + 7;
        stack<int> st1, st2;
        vector<int> left(n), right(n);

        for (int i = 0; i < n; i++)
        {
            while (!st1.empty() && arr[st1.top()] > arr[i])
            {
                st1.pop();
            }
            left[i] = st1.empty() ? i + 1 : i - st1.top();
            st1.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st2.empty() && arr[st2.top()] >= arr[i])
            {
                st2.pop();
            }
            right[i] = st2.empty() ? n - i : st2.top() - i;
            st2.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            long long contri = (1LL * left[i] * arr[i]) % mod;
            contri = (contri * right[i]) % mod;
            total = (total + contri) % mod;
        }
        return total;
    }
};