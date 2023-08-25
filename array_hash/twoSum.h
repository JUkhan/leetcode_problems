#include "../print.h"

//1. Two Sum
//https://leetcode.com/problems/two-sum/

/**
 * Finds two indices in the given vector such that the corresponding elements sum up to the target value.
 * 
 * This function searches for a pair of indices in the input vector 'nums' such that the elements at those
 * indices sum up to the specified 'target'. If such indices are found, they are returned as a vector.
 * 
 * @param nums The input vector of integers.
 * @param target The target value to achieve by adding two elements from the vector.
 * @return A vector containing two indices whose elements add up to the target value.
 *         If no such indices are found, an empty vector is returned.
 */
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];
        if (map.find(diff) != map.end())
            return vector<int>{i, map[diff]};
        map[nums[i]] = i;
    }
    return vector<int>();
}

void run(){
    vector<int> nums{2,7,11,15};
    int target=9;
    auto res=twoSum(nums, target);
    cout<<"twoSum:"<<endl;
    print(res);
}