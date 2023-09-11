#include "../print.h"

// 895. Maximum Frequency Stack
// https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack
{
private:
    unordered_map<int, int> map;
    unordered_map<int, vector<int>> data;
    int top = INT_MIN;

public:
    FreqStack()
    {
    }

    void push(int val)
    {
        
        auto it = map.find(val);
        int index;
        if (it == map.end())
        {
            map.insert({val, 1});
            index = 1;
        }
        else
        {
            it->second++;
            index = it->second;
        }
        auto it2=data.find(index);
        if (it2==data.end())
            data.insert({index, vector<int>{val}});
        else
            it2->second.push_back(val);
        top=max(top, index);
    }

    int pop()
    {
        
        auto it = data.find(top);
        int res = it->second.back();
        it->second.pop_back();
        auto m = map.find(res);
        m->second--;
        if (it->second.empty())
        {
            top--;
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 * ["pop","push","pop","push","pop","push","pop","push","pop","pop","pop","pop","pop","pop"]
   [[],[6],[],[1],[],[1],[],[4],[],[],[],[],[],[]]
 */

int main(int argc, char const *argv[])
{
    FreqStack *obj = new FreqStack();
    obj->push(4);
    obj->push(0);
    obj->push(9);
    obj->push(3);
    obj->push(4);
    obj->push(2);
    cout << obj->pop() << " ";
    obj->push(6);
    cout << obj->pop() << " ";
    obj->push(1);
    cout << obj->pop() << " ";
    obj->push(1);
    cout << obj->pop() << " ";
    obj->push(4);
    cout << obj->pop() << " ";
    cout << obj->pop() << " ";
    cout << obj->pop() << " ";
    cout << obj->pop() << " ";
    cout << obj->pop() << " ";
    cout << obj->pop() << " ";

    return 0;
}
