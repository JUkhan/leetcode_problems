#include "../print.h"

class MyStack
{
private:
    queue<int> q;

public:
    MyStack()
    {
        
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        int size = q.size()-1;
        int lastValue = 0;
        for (int i = 0; i < size; i++)
        {
            lastValue = q.front();
            q.pop();
            q.push(lastValue);
        }
        lastValue= q.front();
        q.pop();
        return lastValue;
    }

    int top()
    {
        int size = q.size();
        int lastValue = 0;
        for (int i = 0; i < size; i++)
        {
            lastValue = q.front();
            q.pop();
            q.push(lastValue);
        }
        
        return lastValue;
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */