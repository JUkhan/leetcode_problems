#include "../print.h"

/**
 * 11. Container With Most Water
 * https://leetcode.com/problems/container-with-most-water/
 */

/**
 * Finds the maximum area of water that can be contained between two vertical lines.
 *
 * @param heights A vector representing the heights of the vertical lines.
 * @return The maximum area of water that can be contained.
 */
int maxArea(vector<int> &heights)
{
    int res = 0;
    int left = 0, right = heights.size() - 1;
    while (left < right)
    {
        int width = right - left;
        int height = min(heights[left], heights[right]);
        res = max(width * height, res);
        if (heights[left] <= heights[right])
            left++;
        else
            right--;
    }

    return res;
}

void run()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    print("maxArea");
    print(maxArea(height));
}