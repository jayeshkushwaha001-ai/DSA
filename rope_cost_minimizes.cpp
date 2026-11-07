#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

int rope_min_cost(vector<int>&arr){
  priority_queue<int , vector<int> , greater<int>> minh;
  for(int i =0; i<arr.size(); i++){
   minh.push(arr[i]);
  }
int cost = 0;
while(minh.size()>=2){
int first = minh.top();
minh.pop();
int second = minh.top();
minh.pop();
cost += first + second;
minh.push(first+second);
}
return cost;
}
};
