#include <queue>
using namespace std;

class MyStack
{
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x)
    {
        q1.push(x);
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // single QUEUE
    void push(int x)
    {
        q1.push(x);
        int sz = q1.size();
        while (sz > 1)
        {
            q1.push(q1.front());
            q1.pop();
            sz--;
        }
    }

    int pop()
    {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() { return q1.front(); }

    bool empty()
    {
        return q1.empty();
    }
};
