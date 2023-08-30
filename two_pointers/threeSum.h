#include "../print.h"

struct hashFunction
{
    size_t operator()(const tuple<int, int, int> &x) const
    {
        return get<0>(x) ^ get<1>(x) ^ get<2>(x);
    }
};

string make_key(int a, int b, int c)
{
    string key = to_string(a) + to_string(b) + to_string(c);
    // sort(key.begin(), key.end());
    return key;
}

// 15. 3Sum
// https://leetcode.com/problems/3sum/

/**
 * Finds all unique triplets in an array that sum up to zero.
 *
 * This function sorts the input array and then uses a two-pointer approach to
 * find the triplets that sum up to zero.
 *
 * @param nums The input vector of integers.
 * @return A vector of vectors where each inner vector represents a triplet that
 *         sums up to zero.
 */
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

void run()
{
    print("threeSum:");

    // vector<int> nums = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    vector<int> nums = {-2, 0, 0, 2, 2};
    //-4 -3 -2 -1 -1 0 0 1 2 3 4
    //[[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]
    auto res = threeSum(nums);

    print(res);
}