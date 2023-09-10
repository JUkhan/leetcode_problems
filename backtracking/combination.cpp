#include "../print.h"
void dfs(int n, int k, vector<vector<int>> &res, vector<int> &cur, int);
// 77. Combinations
// https://leetcode.com/problems/combinations/

/**
 * Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
 *
 *You may return the answer in any order.
 */
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> cur;
    dfs(n, k, res, cur, 1);
    return res;
}

void dfs(int n, int k, vector<vector<int>> &res, vector<int> &cur, int index)
{
    if (cur.size() == k)
    {
        res.push_back(cur);
        return;
    }

    for (int i = index; i <= n; i++)
    {
        cur.push_back(i);
        dfs(n, k, res, cur, i+1 );
        cur.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    // Input: n = 4, k = 2
    // Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
    int n = 4, k = 2;
    auto res = combine(n, k);
    print(res);
    return 0;
}
