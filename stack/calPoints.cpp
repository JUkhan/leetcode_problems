#include "../print.h"

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(string c:operations){
            if(c=="D"){
                s.push(s.top()*2);
            }
            else if(c=="C"){
                s.pop();
            }
            else if(c=="+"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.push(a);
                s.push(a+b);
            }
            else{
                s.push(atoi(c.c_str()));
            }
        }
        int sum=0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
    
};

int main(int argc, char const *argv[])
{
    vector<string> str={"5","2","C","D","+"};
   
    string join=accumulate(str.begin(), str.end(), string(""));
    print(join);
    
    Solution s;
    int res = s.calPoints(str);
    print(res);
    return 0;
}
