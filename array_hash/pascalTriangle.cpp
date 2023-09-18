//
// Created by Jasim Uddin on 13/9/23.
//

#include "../print.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back(vector<int>{1});
        int n=2;
        while(n<=numRows) {
            vector<int> t(n,1);
            for (int i = 1; i < n-1; i++) {
                auto pre_row=res.back();
                t[i]=pre_row[i-1]+pre_row[i];
            }
            res.push_back(t);
            n++;
        }
        return res;
    }
};

int main(){
    print("Pascal Triangle");
    Solution s;
    auto res=s.generate(5);
    print(res);
}
