#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:

vector<int> k_largest(int k , vector<int>& arr ){

  priority_queue<int , vector<int> , greater<int>> minh;
  for(int i = 0; i<arr.size(); i++){
    minh.push(arr[i]);
   if(minh.size()> k){
     minh.pop();
   }
}
vector<int> ans;
    while (!minh.empty()) {
     ans.push_back(minh.top());
       minh.pop();
    }

return ans;
  }
};
