#include "../print.h"
//121. Best Time to Buy and Sell Stock
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

/**
* You are given an array prices where prices[i] is the price of a given stock on the ith day.
*
* You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
*
* Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
int maxProfit(vector<int> &prices)
{
    int p = 0;
    int buy = 0, sell = 1, N = prices.size();
    while (sell < N)
    {
        if (prices[sell] > prices[buy])
            p = max(p, prices[sell] - prices[buy]);
        else
            buy = sell;
        sell++;
    }
    return p;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    print("maxProfit:");
    print(maxProfit(prices));
    return 1;
}