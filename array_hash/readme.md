
`❤` Sometimes we need output should be group wise but group name should not exist like:
```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
processed groups = {
    "abt" : ["bat"],
    "ant" : ["nat","tan"],
    "aet" : ["ate","eat","tea"]
}
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```
Solution is pretty good. But keep in mind `map` is not sequential guaranteed. If output is required to maintain the order as it has been put on the map, need to take the approach directly put on the `vector`.

## Example
```c++
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    unordered_map<string, int> map;
    int c = 0;
    for (string k : strs)
    {
        string val = k; //copy k to val before sorting. so that we can put original value in the vector.
        sort(k.begin(), k.end());
        if (map.find(k) != map.end())
        {
            res[map[k]].push_back(val);
        }
        else
        {
            res.push_back(vector<string>{val});
            map[k] = c++;
        }
    }
    return res;
}
```

`❤` In the `grid` problems sometimes we need to validate a `value` already exist in current `row` or `col` or inside a `subGrid`. A `HashMap` can solve this issue `but` keep in mind whether it's `possible` to transform the `value` at index level and put a `flag` on it so that you can have a check whether the `flag` is `ON` or `OFF` (better approach).

## Example
```c++
bool isValidSudoku(vector<vector<char>> &board)
{
    const int size = 9;
    bool rows[size][size] = {false};
    bool cols[size][size] = {false};
    bool subset[size][size] = {false};

    for (int i = 0; i < size; i++)
    {
        int cv = (i / 3) * 3;
        for (int j = 0; j < size; j++)
        {
            char ch = board[i][j];
            if (ch == '.')
                continue;

            int index = ch - '0' - 1;
            int subIndex = cv + (j / 3);
            if (rows[i][index] || cols[j][index] || subset[subIndex][index])
            {
                return false;
            }
            rows[i][index] = true;
            cols[j][index] = true;
            subset[subIndex][index] = true;
        }
    }
    return true;
}
```

`❤` Sometimes partial processing ( `partial_sum | scan` ) is necessary to calculate some operations easily. May be we need to apply partial process both directions `start to end` and `end to start`.

```c++
vector<int> productExceptSelf(vector<int> &nums)
{
    const int N = nums.size() + 1;
    vector<int> prefix(N, 1), postfix(N, 1), res(N - 1);
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1, [](int a, int b)
                { return a * b; });
    partial_sum(nums.rbegin(), nums.rend(), postfix.begin() + 1, [](int a, int b)
                { return a * b; });
    reverse(postfix.begin(), postfix.end());
    
    for (int i = 0; i < nums.size(); i++)
    {
        res[i] = prefix[i] * postfix[i + 1];
    }
    return res;
}
```

```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

`❤` Most Frequent Elements - using Bucket Sort technique - O(n) time complexity. Element Frequency never exceed array size. A `HashMap` for frequency counting and a `vector<vector<int>>` for ordering frequency - here index value should be element's frequencies. A single frequency index can have multiple elements.
```c++
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    int n = nums.size() + 1;
    vector<vector<int>> store(n);
    for (auto n : nums) map[n]++;
    for (auto &p : map) store[p.second].push_back(p.first);
    vector<int> res;
    for (auto it = store.rbegin(); it != store.rend(); ++it)
    {
        if (k <= 0)
            break;
        if (it->size())
        {
            k -= it->size();
            res.insert(res.begin(), it->begin(), it->end());
        }
    }
    return res;
}
```
```
Input: nums = [1,3,1,2,2,1], k = 2
Output: [1,2]
```