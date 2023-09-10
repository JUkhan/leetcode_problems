#include "../print.h"

// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

/*
    Given an integer array of unique elements, return all possible subsets (the power set)
    Ex. nums = [1,2,2] -> [[],[1],[1,2],[1,2,2],[2],[2,2]]

    Backtracking, generate all combos, push/pop + to explore new combos, skip duplicates

    Time: O(n x 2^n)
    Space: O(n)
*/

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> curr;
        vector<vector<int>> result;

        dfs(nums, 0, curr, result);
        return result;
    }

private:
    void dfs(vector<int> &nums, int start, vector<int> &curr, vector<vector<int>> &result)
    {
        result.push_back(curr);
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    // Input: nums = [1,2,2]
    // Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
    Solution s;
    vector<int> nums = {1, 2, 2};
    auto res = s.subsetsWithDup(nums);
    print(res);
    return 0;
}
