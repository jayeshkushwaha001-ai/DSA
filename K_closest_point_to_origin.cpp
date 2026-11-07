#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

vector<vector<int>> k_closest_to_origin(int k , vector<vector<int>>& arr){
  priority_queue<pair<int , pair<int , int>>> maxh;
  for(int i =0; i<arr.size(); i++){
  maxh.push({arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1] , {arr[i][0], arr[i][1]}});
  if(maxh.size()>k){
   maxh.pop();
  }
  }
vector<vector<int>> ans;
while(!maxh.empty()){
ans.push_back({maxh.top().second.first, maxh.top().second.second});
maxh.pop();
}


return ans;
}
};
