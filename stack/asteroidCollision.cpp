#include "../print.h"

/*
 https://leetcode.com/problems/asteroid-collision/
 735. Asteroid Collision
Medium

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Input: asteroids = [5,10,-5]
Output: [5,10]
*/
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> s;

        for (int i = 0; i < asteroids.size(); i++)
        {
            int a = asteroids[i];

            while (!s.empty() && s.back() > 0 && a < 0)
            {
                int diff = s.back() + a;
                if (diff > 0)
                {
                    a = 0;
                }
                else if (diff < 0)
                {
                    s.pop_back();
                }
                else
                {
                    a = 0;
                    s.pop_back();
                }
            }

            if (a)
                s.push_back(asteroids[i]);
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> asteroids = {-2, -1, 1, 2};
    Solution s;
    vector<int> res = s.asteroidCollision(asteroids);
    print(res);
    asteroids = {10, 2, -5};
    res = s.asteroidCollision(asteroids);
    print(res);
    return 0;
}
