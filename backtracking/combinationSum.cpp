#include "../print.h"

// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> cur;

        //def(candidates, target, cur, res, 0, 0);
        dfs(candidates, target, 0, 0, cur, res);
        return res;
    }

    void def(vector<int> &candidates, int target, vector<int> &cur, vector<vector<int>> &res, int index, int total)
    {
        if (total == target)
        {
            res.push_back(cur);
            return;
        }
        if (index >= candidates.size() || total > target)
        {
            return;
        }
        cur.push_back(candidates[index]);
        def(candidates, target, cur, res, index, total + candidates[index]);
        cur.pop_back();
        def(candidates, target, cur, res, index + 1, total);
    }
    void dfs(vector<int>& candidates, int target, int sum, int start, vector<int>& curr, vector<vector<int>>& result) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i, curr, result);
            curr.pop_back();
        }
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    // Output: [[2,2,3],[7]]
    Solution s;
    auto res = s.combinationSum(candidates, target);
    print(res);
    return 0;
}
