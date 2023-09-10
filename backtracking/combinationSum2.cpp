#include "../print.h"
/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        dfs(candidates, target, 0, 0, curr, res);
        return res;
    }

private:

    void dfs(vector<int> &candidates, int target, int sum, int start, vector<int> &curr, vector<vector<int>> &result)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            curr.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i + 1, curr, result);
            curr.pop_back();
        }
    }
  
};

int main(int argc, char const *argv[])
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution s;
    auto res = s.combinationSum2(candidates, target);
    print(res);
    return 0;
}
