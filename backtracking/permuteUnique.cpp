#include "../print.h"
/*
47. Permutations II
https://leetcode.com/problems/permutations-ii/

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
*/
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> curr;
        for (int n : nums)
            map[n]++;

        dfs(nums, curr, res);
        return res;
    }

private:
    unordered_map<int, int> map;
    void dfs(vector<int> &nums, vector<int> &curr, vector<vector<int>> &res)
    {
        if (curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }

        for (auto &it : map)
        {
            if (it.second > 0)
            {
                curr.push_back(it.first);
                it.second--;
                dfs(nums, curr, res);
                curr.pop_back();
                it.second++;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 2};
    Solution s;
    auto res = s.permuteUnique(nums);
    print(res);
    return 0;
}
