#include "../print.h"
// 1209. Remove All Adjacent Duplicates in String II
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        for(char c : s){
            if(!st.empty() && st.top().first==c){
                st.top().second++;
                if(st.top().second==k) st.pop();
            }
            else st.push({c,1});
        }
        string ss;
        while (!st.empty())
        {
            ss+=string(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ss.begin(), ss.end());
        
        return ss;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string res=s.removeDuplicates("deeedbbcccbdaa", 3);
    print(res);
    
    return 0;
}
