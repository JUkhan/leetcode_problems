#include "../print.h"

// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

/**
 * Checks whether the given vector contains any duplicate integers.
 *
 * This function iterates through the provided vector and uses an unordered set
 * to track the integers encountered. If a duplicate integer is found, the function
 * returns true; otherwise, it returns false.
 *
 * @param nums The vector of integers to be checked for duplicates.
 * @return True if the vector contains duplicates, false otherwise.
 */
bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> set;
    for (int v : nums)
    {
        if (set.find(v) != set.end())
        {
            return true;
        }
        set.insert(v);
    }
    return false;
}

void run()
{
    vector<int> nums{1, 2, 3, 1};
    auto res = containsDuplicate(nums);
    cout << "containsDuplicate: " << res << endl;
}