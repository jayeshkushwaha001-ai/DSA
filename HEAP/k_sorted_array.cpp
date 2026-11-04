#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> k_sort(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> minh;
        
        for (int i = 0; i < arr.size(); i++) {
            minh.push(arr[i]);
            
      
            if (minh.size() > k) {
                ans.push_back(minh.top());
                minh.pop();
            }
        }

    
        while (!minh.empty()) {
            ans.push_back(minh.top());
            minh.pop(); 
        }

        return ans;
    }
};
