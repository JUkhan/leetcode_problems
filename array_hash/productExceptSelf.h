#include "../print.h"

// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/

vector<int> productExceptSelf_old(vector<int> &nums)
{

    int product = accumulate(nums.begin(), nums.end(), 1, [](int a, int b)
                             { return a * b; });
    
    vector<int> res(nums.size());

    transform(nums.begin(), nums.end(), res.begin(), [&](int a)
              { return product / a; });
    return res;
}

/**
 * Calculates the product of all elements in the input vector except the element at the current position.
 *
 * This function computes the product of all elements in the 'nums' vector, except for the element at
 * the current position. It does this by maintaining prefix and postfix product arrays and then combining
 * their values to obtain the final result.
 *
 * @param nums The input vector of integers.
 * @return A vector containing the products of all elements except the element at the current position.
 */
vector<int> productExceptSelf(vector<int> &nums)
{
    const int N = nums.size() + 1;
    vector<int> prefix(N, 1), postfix(N, 1), res(N - 1);
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1, [](int a, int b)
                { return a * b; });
    partial_sum(nums.rbegin(), nums.rend(), postfix.begin() + 1, [](int a, int b)
                { return a * b; });
    reverse(postfix.begin(), postfix.end());
    
    for (int i = 0; i < nums.size(); i++)
    {
        res[i] = prefix[i] * postfix[i + 1];
    }
    return res;
}

void run()
{
    vector<int> nums{1, 2, 3, 4};
    auto res = productExceptSelf(nums);
    cout << "productExceptSelf:" << endl;
    print(res);
}