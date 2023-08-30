#include "../print.h"

// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/

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

    print(maxL);
    print(maxR);
    print(minLR);

    return accumulate(res.begin(), res.end(), 0);
}

int trap(vector<int> &heights)
{
    const int N = heights.size();
    if (N == 0)
        return 0;
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

void run()
{
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // output: 23
    print("Trap rain water:");
    print(trap(heights));
}