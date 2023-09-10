#include "../print.h"

// 78 subsets
// https://leetcode.com/problems/subsets/

void dfs(vector<int> &nums, int start, vector<int> &curr, vector<vector<int>> &result)
{
    result.push_back(curr);
    for (int i = start; i < nums.size(); i++)
    {
        curr.push_back(nums[i]);
        dfs(nums, i + 1, curr, result);
        curr.pop_back();
    }
}

/**
 * Given an integer array nums of unique elements, return all possible subsets(the power set).
 *The solution set must not contain duplicate subsets. Return the solution in any order.
 */
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> cur;
    dfs(nums, 0, cur, res);

    return res;
}



int main()
{
    // Input: nums = [1,2,3]
    // Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    vector<int> nums = {1, 2, 3};
    auto res = subsets(nums);
    print(res);
}