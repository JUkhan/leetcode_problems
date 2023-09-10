#include "../print.h"
//402. Remove K Digits
//https://leetcode.com/problems/remove-k-digits/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (char c : num)
        {
            while (k > 0 && !st.empty() && st.top() > c)
            {
                k--;
                st.pop();
            }
            st.push(c);
        }
        while (k > 0)
        {
            k--;
            st.pop();
        }
        string res;

        /*
        This type of string concatenation is dangerous shown 
        Memory Limit Exceeded when need to concate lots of strings.

        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }*/

       
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin() , res.end());

        // Remove the zeros from the left if they exist.
        while (res[0] == '0')
            res.erase(0, 1);

        return res.empty() ? "0" : res;
    }
};

int main(int argc, char const *argv[])
{

    Solution s;
    string res = s.removeKdigits("6543210", 3);
    print(res);
    return 0;
}
