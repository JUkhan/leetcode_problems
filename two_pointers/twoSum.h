#include "../print.h"

//167. Two Sum II - Input Array Is Sorted
//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

/**
 * Find the indices of two numbers in a sorted array that add up to the target.
 * 
 * Given a sorted array of integers and a target value, this function finds two numbers
 * whose sum equals the target. The function uses a two-pointer approach to efficiently
 * search for the required numbers.
 * 
 * @param numbers The input vector of sorted integers.
 * @param target The target value for which the sum of two numbers is required.
 * @return A vector containing the indices (1-indexed) of the two numbers that add up to the target.
 */
 vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0, end=numbers.size()-1;
        while (start<end)
        {
            const int sum=numbers[start]+numbers[end];
            if(sum==target)return vector<int>{start+1, end+1};
            else if(sum<target)start++;
            else end--;

        }
        return vector<int>();
        
}
void run(){
    vector<int> nums={2,7,11,15};
    int target=9;
    auto res=twoSum(nums, target);
    print("twoSum:");
    print(res);
}