#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:

vector<int> sort_frequency(vector<int>&arr){
unorderd_map<int, int> mpp;
for(int i =0; i<arr.size(); i++){
mpp[arr[i]]++;
}

priority_queue<pair<int, int>> maxh;
  for (auto it = mpp.begin(); it != mpp.end(); it++) {
            maxh.push({it->second, it->first}); 
  }
vector<int>ans;
while(maxh.size()>0){
int freq = maxh.top().first;
int data = maxh.top().second;
for(int i=0; i<freq; i++){
ans.push_back(data);
}
maxh.pop();
}

return ans;
}
};
