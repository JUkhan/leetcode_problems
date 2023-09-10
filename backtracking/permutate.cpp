#include "../print.h"
void dfs(vector<int> &nums, vector<vector<int>> &res, int);
// 46. Permutations
// https://leetcode.com/problems/permutations/

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    dfs(nums, res, 0);
    return res;
}

void dfs(vector<int> &nums, vector<vector<int>> &res, int start)
{
    if (start == nums.size())
    {
        res.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++)
    {
        swap(nums[i], nums[start]);
        dfs(nums, res, start +1);
        swap(nums[i], nums[start]);
    }
}

int main()
{
    // Input: nums = [1,2,3]
    // Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    vector<int> nums = {1, 2, 3};
    auto res = permute(nums);
    print(res);
    string name="Jasim";
    swap(name[0], name[4]);
    print(name);
    return 0;
}
