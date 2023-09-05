#include "../print.h"

// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

/**
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
 *
 * The testcases will be generated such that the answer is unique.
 */
string minWindow(string s, string t)
{
    if (t.size() > s.size())
        return "";
    unordered_map<char, int> t_map;
    int counter = 0;
    // calculate map value and # of char need to match that must be in s
    for (char ch : t)
    {
        t_map[ch]++;
        counter++;
    }

    int l = 0, r = 0;
    // start index and size
    pair<int, int> p = {0, INT_MAX};

    while (r < s.size())
    {
        char ch = s[r];

        // if ch exist in t_map then counter--
        if (t_map[ch] > 0)
            counter--;

        // all key value should be -ve
        t_map[ch]--;

        r++;

        // if found counter==0 then try to minimize the window size
        while (counter == 0)
        {
            if ((r - l) < p.second)
                p = {l, r - l};
            ch = s[l];

            t_map[ch]++;

            // when char exists in t, increase
            if (t_map[ch] > 0)
                counter++;

            l++;
        }
    }
    if (p.second != INT_MAX)
        return s.substr(p.first, p.second);
    return "";
}

int main()
{

    print("minWindow");
    string s = "aa", t = "aa";
    print(minWindow(s, t)); // BANC
}