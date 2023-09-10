#include "../print.h"

class Solution
{
public:
    string simplifyPath(string path)
    {
        const int N = path.size();
        stack<string> stack;
        for (int i = 0; i < N; i++)
        {
            if (path[i] == '/')
                continue;

            string t = "";
            while (i < N && path[i] != '/')
            {
                t += path[i];
                i++;
            }

            if (t == ".")
                continue;
            else if (t == "..")
            {
                if (!stack.empty())
                    stack.pop();
            }
            else
                stack.push(t);
        }
        string res = "";
        while (!stack.empty())
        {
            res = '/' + stack.top() + res;
            stack.pop();
        }
        return res.empty() ? "/" : res;
    }
};

int main(int argc, char const *argv[])
{
    
    /*
    "/home/"
 "/../"
 "/home//foo/"
 "/a/./b/../../c/"
 "/a/../../b/../c//.//"
 "/a//b////c/d//././/.."*/
    Solution s;
    string res = s.simplifyPath("/a/./b/../../c/");
    print(res);
    return 0;
}
