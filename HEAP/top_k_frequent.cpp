#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
  
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

        for (auto it = mpp.begin(); it != mpp.end(); it++) {
            minh.push({it->second, it->first}); 

            
            if (minh.size() > (size_t)k) {
                minh.pop();
            }
        }
        vector<int> ans;
        while (!minh.empty()) {
            ans.push_back(minh.top().second); 
            minh.pop();
        }

        return ans;
    }
};
