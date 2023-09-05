#include "../print.h"

// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 */
bool isValid(string s)
{
    stack<char> stack;
    unordered_map<int, int> map{{'(', ')'}, {'{', '}'}, {'[', ']'}};
    for (char v : s)
    {
        if (v == '(' || v == '{' || v == '[')
            stack.push(map[v]);
        else if (v == ')' || v == '}' || v == ']')
        {
            if (stack.top() != v)
                return false;
            stack.pop();
        }
    }

    return stack.empty();
}

// 150. Evaluate Reverse Polish Notation

int evalRPN(vector<string> &tokens)
{
    stack<int> s;
    auto opds = [&]()
    {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        return pair<int, int>(a, b);
    };
    for (string c : tokens)
    {
        if (c == "+")
        {
            auto a = opds();
            s.push(a.first + a.second);
        }
        else if (c == "-")
        {
            auto a = opds();
            s.push(a.first - a.second);
        }
        else if (c == "/")
        {
            auto a = opds();
            s.push(a.first / a.second);
        }
        else if (c == "*")
        {
            auto a = opds();
            s.push(a.first * a.second);
        }
        else
        {
            s.push(atoi(c.c_str()));
        }
    }
    return s.top();
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    function<void(int, int, string)> process = [&](int o, int c, string s)
    {
        if (o == c && o == n)
        {
            res.push_back(s);
            return;
        }
        if (o < n)
            process(o + 1, c, s + '(');
        if (c < o)
            process(o, c + 1, s + ')');
    };
    process(0, 0, "");
    return res;
}

// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    const int N = temperatures.size();
    vector<int> res(N);
    // pair of day, temp
    stack<pair<int, int>> stack;
    for (int i = 0; i < N; i++)
    {
        int curDay = i;
        while (!stack.empty() && stack.top().second < temperatures[i])
        {
            int preDay = stack.top().first;
            res[preDay] = curDay - preDay;
            stack.pop();
        }
        stack.push({curDay, temperatures[i]});
    }
    return res;
}

// 853. Car Fleet
// https://leetcode.com/problems/car-fleet/
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int res = 0;
    vector<pair<int, double>> pos_speed;
    for (int i = 0; i < position.size(); i++)
    {
        pos_speed.push_back({position[i], (double)(target - position[i]) / speed[i]});
    }
    sort(pos_speed.begin(), pos_speed.end());
    print(pos_speed);
    double maxTime = 0.0;

    for (int i = pos_speed.size() - 1; i >= 0; i--)
    {
        double time = pos_speed[i].second;
        if (time > maxTime)
        {
            maxTime = time;
            res++;
        }
    }
    return res;
}

//84. Largest Rectangle in Histogram
//https://leetcode.com/problems/largest-rectangle-in-histogram/description/


int largestRectangleArea(vector<int> &heights)
{
    int const N = heights.size();
    int res = 0;
    int i = 0;
    stack<pair<int, int>> stack;
    while (i < N)
    {
        int start = i;
        int cur_height = heights[i];

        while (!stack.empty() && cur_height < stack.top().second)
        {
            auto pair = stack.top();
            res = max(res, pair.second * (i - pair.first));
            stack.pop();
            start=pair.first;
        }

        stack.push({start, cur_height});
        i++;
    }

    while (!stack.empty())
    {
        auto pair = stack.top();
        res = max(res, pair.second * (N - pair.first));
        stack.pop();
    }

    return res;
}

int main()
{
    print("Valid Parentheses");
    string s = "()[]{}";
    print(isValid(s));

    print("evalRPN");
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    print(evalRPN(tokens)); // 22

    print("generateParenthesis");
    auto vp = generateParenthesis(3);
    print(vp);

    print("dailyTemperatures");
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    temperatures = dailyTemperatures(temperatures);
    print(temperatures);
    // Output: [1,1,4,2,1,1,0,0]

    print("car fleet");
    int target = 12;
    // vector<int> position = {10,8,0,5,3}, speed = {2,4,1,1,3};
    target = 10;
    vector<int> position = {6, 8}, speed = {3, 2};
    print(carFleet(target, position, speed)); // 3

    print("largestRectangleArea");
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    print(largestRectangleArea(heights)); // 10
}