#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
int kth_smallest(int k , vector<int>& arr){
  priority_queue<int> maxh;
  for(int i =0, i<arr.size(); i++){
     maxh.push(arr[i]);
     if(maxh.size()>k){
       maxh.pop();
     }
  }
  return maxh.top();
}
};
  
