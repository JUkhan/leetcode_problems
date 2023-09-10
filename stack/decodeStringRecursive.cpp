#include "../print.h"

//394. Decode String
//https://leetcode.com/problems/decode-string/

class Solution
{
public:
    string decodeString(string s)
    {
        const int N = s.size();
        stack<string> st;
        for (int i = 0; i < N; i++)
        {
            string digits = "", str = "";
            while (i < N && !(s[i] == '[' || s[i] == ']'))
            {
                if (isdigit(s[i]))
                    digits += s[i];
                else
                    str += s[i];
                i++;
            }
            if (s[i] == '[')
                st.push("[");

            if (!str.empty())
                st.push(str);
            if (!digits.empty())
                st.push(digits);

            if (s[i] == ']')
            {
                string res=decoding(st);
                auto it = substr(s,i+1);
                if(it.first.empty()) st.push(res);
                else st.push(res+decodeString(it.first));
                i=it.second;
            }
        }

        
        if (!st.empty())
            return st.top();
        return "";
    }

private:
    pair<string, int> substr(string s, int i){ 
        stack<bool> st;
        string res="";
        while (i<s.size())
        {
            if(s[i]==']' && st.empty())break;
            if(s[i]=='[')st.push(true);
            else if(s[i]==']')st.pop();
            res+=s[i];
            i++;
        }
        
        return {res, i-1};
    }
    string mul(string s, int times)
    {
        string res = "";
        for (int i = 0; i < times; i++)
            res += s;
        return res;
    }

    string decoding(stack<string> &st)
    {
        string s1 = st.top();
        st.pop();
        if(st.empty()) return s1;
        string t = st.top();
        st.pop();
        
        string decoded = mul(s1, atoi(t.c_str()));
        if (st.top() != "[")
        {
            decoded = st.top() + decoded;
            st.pop();
        }
        st.pop();
        return decoded;
    }
};

int main(int argc, char const *argv[])
{
    /*
    "3[a]2[bc]"
    "3[a2[c]]"
    "2[abc]3[cd]ef"
    */
    Solution s;
    string res = s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
    //"3[z]2[2[y]pq4[2[jk]e1[f]]]ef"
    //"zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef"
    
    print(res);
    
    return 0;
}