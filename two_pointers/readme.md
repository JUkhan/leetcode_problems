`❤` threeSum problem is awesome. You need to consider couple of points there
+ start to sort the nums array
+ if nums[i]>0 stops iteration because sum of three nums never become `zero` because every next element is gradually increasing (sorted)
+ Ignore the same consecutive numbers
+ apply the binary search when you need step ahead | behind.

## Solution
```c++
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i - 1] == nums[i]) continue;
        auto j = nums.begin() + i + 1, k = nums.end() - 1;
        while (j < k)
        {
            int sum = nums[i] + *j + *k;
            if (sum == 0)
            {
                res.push_back({nums[i], *j, *k});
                k = lower_bound(j + 1, k, *k);
                j = upper_bound(j + 1, k, *j);
                k--;
            }
            else if (sum > 0) k--;
            else j++;
        }
    }
    return res;
}
```
`❤`  Container With Most Water - Finds the maximum area of water that can be contained between two vertical lines. 

To solve this problem we can have:
+ two pointers `left` and `right`
+ loop until `left` < `right`
+ find `width` = `right` - `left`
+ find `height` = `min(heights[left], heights[right])`
+ calculate `maxArea = max(width * height, maxArea);` 
+ `left++` if `heights[left] <= heights[right]` otherwise `right--`


## Solution
```c++
int maxArea(vector<int> &heights)
{
    int maxArea = 0;
    int left = 0, right = heights.size() - 1;
    while (left < right)
    {
        int width = right - left;
        int height = min(heights[left], heights[right]);
        maxArea = max(width * height, maxArea);
        if (heights[left] <= heights[right])
            left++;
        else
            right--;
    }

    return maxArea;
}
```

`❤` Trapping rain water - explaining two algorithms to solve this problem:

`Algo-1 tc:O(n), sc:O(n)`
+ calculate `left max`
+ calculate `right max`
+ calculate min between `left max` and `right max`
+ calculate `trapping` points 
+ and return the sum of every `trapping` points.
## Solution 1
```c++
int trap_old(vector<int> &heights)
{
    const int N = heights.size();
    vector<int> maxL(N), maxR(N), minLR(N), res(N);
    int l = 0;

    for (int i = 1; i < N; i++)
    {
        l = max(l, heights[i - 1]);
        maxL[i] = l;
    }

    int r = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        r = max(r, heights[i + 1]);
        maxR[i] = r;
    }

    for (int i = 0; i < N; i++)
    {
        minLR[i] = min(maxL[i], maxR[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (minLR[i] > heights[i])
            res[i] = minLR[i] - heights[i];
    }

    return accumulate(res.begin(), res.end(), 0);
}
```
`Algo-2 tc:O(n), sc:O(1)`

This is easy two `pointers` solution
+ two pointers `l` and `r`
+ and its corresponding `maxL` and `maxR`
+ loop until `l` < `r`
+ calculate `trapping` point 
## Solution 2
```c++
int trap(vector<int> &heights)
{
    const int N = heights.size();
    if (N == 0) return 0;
    int res = 0, l = 0, r = N - 1;
    int maxL = heights[l], maxR = heights[r];
    while (l < r)
    {
        if (maxL <= maxR)
        {
            l++;
            if (maxL > heights[l])
                res += maxL - heights[l];
            maxL = max(maxL, heights[l]);
        }
        else
        {
            r--;
            if (maxR > heights[r])
                res += maxR - heights[r];
            maxR = max(maxR, heights[r]);
        }
    }

    return res;
}
```