//
// Created by Jasim Uddin on 13/9/23.
//
#include "../print.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> map;
        for(string s:emails){
            string k=get_email(s);
            cout<<k<<endl;
            map[k]++;
        }
        return map.size();
    }
    string get_email(string s){
        string r="";
        bool is_plus=false, is_at=false;
        for(char a: s){
            if(a=='@'){
                is_at=true;
                is_plus=false;
            }
            if(!is_at &&(is_plus|| a=='.')) continue;
            if(a=='+'){
                is_plus=true;
                continue;
            }
            r+=a;
        }
        return r;
    }
};

int main(){
    Solution s;
    vector<string> emails={"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    auto res=s.numUniqueEmails(emails);
    print(res);
}