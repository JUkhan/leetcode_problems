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
            if (s[i] == ']')
            {
                string ss="";
                while(st.top()!="["){
                    ss=st.top()+ss;
                    st.pop();
                }
                
                st.pop();
                string times="";
                while (!st.empty() && isdigit(st.top()[0]))
                {
                    times=st.top()+times;
                    st.pop();
                }
                st.push(mul(ss, atoi(times.c_str())));
                
            }
            else{
                string t;
                t+=s[i];
                st.push(t);
               
            }
        }
        string res="";
        while (!st.empty()){
           res= st.top()+res;
           st.pop();
        }
        return res;
    }

private:
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
        string t = st.top();
        st.pop();
        string decoded = mul(s1, atoi(t.c_str()));
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
