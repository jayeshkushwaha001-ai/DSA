#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }

    int peek()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }

    bool empty() { return s1.empty(); }


    // O(1)
    int pop(){
        peek();
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.top();
            }
        }
        return s2.top();
    }

    bool empty(){
        return s1.empty() && s2.empty();
    }
};
