/**
 * @file
 * @brief LeetCode problem 128: Longest Consecutive Sequence
 * @link https://leetcode.com/problems/longest-consecutive-sequence/
 */

#include "../print.h"


/**
 * Find the length of the longest consecutive sequence of elements in an unsorted array.
 * 
 * Given an unsorted array of integers, this function calculates the length of the longest
 * consecutive sequence of elements.
 * 
 * @param nums The input vector of integers.
 * @return The length of the longest consecutive sequence.
 */
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> set(nums.begin(), nums.end());
    int longest = 0;
    for (int val : nums)
    {
        if (!set.count(val - 1))
        {
            int count = 0;
            while (set.find(val+count) != set.end())
            {
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main()
{
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    print(nums);
    print("longestConsecutive:");
    cout << longestConsecutive(nums) << endl;
    return 0;
}