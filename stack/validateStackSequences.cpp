#include "../print.h"
/*
https://leetcode.com/problems/validate-stack-sequences/
946. Validate Stack Sequences
Medium

Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true

*/
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int index = 0;
        for (int n : pushed)
        {
            if (n == popped[index])
            {
                index++;
                while (index<popped.size() && !s.empty() && s.top() == popped[index])
                {
                    index++;
                    s.pop();
                }
            }
            else
                s.push(n);
        }
        return s.empty();
    }
};

int main(int argc, char const *argv[])
{
    vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
    Solution s;
    auto res = s.validateStackSequences(pushed, popped);
    print(res);
    return 0;
}
