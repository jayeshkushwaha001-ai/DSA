#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long min;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long value = val;
        if (st.empty()) {
            st.push(value);
            min = value;
        } 
        else {
    
            if (value >= min) {
                st.push(value);
            } 
            else {
           
                st.push(2 * value - min);
                min = value; 
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        
        long long curr = st.top();
        st.pop();
        
   
        if (curr < min) {
            min = 2 * min - curr;
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        
        long long curr = st.top();
      
        if (curr < min) {
            return min;
        } 
        else {
            return curr;
        }
    }
    
    int getMin() {
        return min; 
    }
};