`❤` One the most important `stack` algorithm is `monotonically increment` or `decrement` that brings time complexity `O(n)` from `O(n^2)`

Find the larger rectangle area from histogram:

## Example
```c++
int largestRectangleArea(vector<int> &heights)
{
    int const N = heights.size();
    int res = 0;
    int i = 0;
    stack<pair<int, int>> stack;
    while (i < N)
    {
        int start = i;
        int cur_height = heights[i];
        //popping up the elm those has lower value and also calculate the area and index
        while (!stack.empty() && cur_height < stack.top().second)
        {
            auto pair = stack.top();
            res = max(res, pair.second * (i - pair.first));
            stack.pop();
            start=pair.first;
        }

        stack.push({start, cur_height});
        i++;
    }

    while (!stack.empty())
    {
        auto pair = stack.top();
        res = max(res, pair.second * (N - pair.first));
        stack.pop();
    }

    return res;
}
```

