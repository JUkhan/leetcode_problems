#include "../print.h"

//456. 132 Pattern
//https://leetcode.com/problems/132-pattern/

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        const int N = nums.size();
        int m = INT_MAX;
        stack<int> st;
        for (int i = 0; i < N; i++)
        { 
            while (!st.empty() && st.top() < nums[i])
            {
                st.pop();
            }
            st.push(nums[i]);
            if (st.size() == 2 && m < st.top())
            {
                return true;
            }
            m = min(m, nums[i]);
        }
        
        return false;
    }
};

int main(int argc, char const *argv[])
{
    //vector<int> v = {1,4,0,-1,-2,-3,-1,-2};
    vector<int> v = {1, 4, 5, 7, 8, 9, 6};
    Solution s;
    bool res = s.find132pattern(v);
    print(res);
    return 0;
}
