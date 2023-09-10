#include "../print.h"

// 901. Online Stock Span
// https://leetcode.com/problems/online-stock-span/description/

class StockSpanner
{
private:
    stack<pair<int, int>> stack;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!stack.empty() && stack.top().first <= price)
        {
            span += stack.top().second;
            stack.pop();
        }
        stack.push({price, span});
        return span;
    }
};