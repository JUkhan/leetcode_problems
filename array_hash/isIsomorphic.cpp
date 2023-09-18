//
// Created by Jasim Uddin on 13/9/23.
//
#include "../print.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        for(int i=0; i<s.size(); i++){
            auto it_s = map.find(s[i]);
            if(it_s==map.end()){

                    map.insert({s[i], t[i]});

            }
            else if(it_s->second!=t[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
Solution s;
bool  res=s.isIsomorphic("bar","foo");
print(res);
}