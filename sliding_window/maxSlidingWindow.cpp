#include "../print.h"



// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

/**
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 *
 * Return the max sliding window.
 */
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    const int N = nums.size();
    vector<int> res;
    deque<int> pq; 
    int l = 0, r = 0;
    while (r < N)
    {
        while(!pq.empty() && nums[pq.back()]<nums[r]){
            pq.pop_back();
        }
        pq.push_back(r);
        if(l>pq.front()){ 
            pq.pop_front();
        }
        if(r+1>=k){
            res.push_back(nums[pq.front()]);
            l++;
        }
        r++;
    }

    return res;
}

int main()
{
    print("maxSlidingWindow");
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto res = maxSlidingWindow(nums, k);
    print(res);
    // Output: [3,3,5,5,6,7] 
}