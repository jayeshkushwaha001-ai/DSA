#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int target = nums1[i];
            int next = -1;

            int j = 0;
            while (j < nums2.size() && nums2[j] != target) {
                j++;
            }
            for (int k = j + 1; k < nums2.size(); k++) {
                if (nums2[k] > target) {
                    next = nums2[k];
                    break;
                }
            }
            ans.push_back(next);
        }
        return ans;
    }
};

