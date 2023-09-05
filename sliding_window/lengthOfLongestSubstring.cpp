#include "../print.h"
// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/**
 * Given a string s, find the length of the longest substring without repeating characters.
 */
int lengthOfLongestSubstring(string s)
{
    int const N = s.size();
    unordered_set<char> set;
    int l = 0, r = 0, ml = 0;
    while (r<N)
    {
        while (set.find(s[r])!=set.end())
        {
            set.erase(s[l]);
            l++;
        }
        set.insert(s[r]);
        ml=max(ml, r-l+1);
        r++;
    }
    
   
    return ml;
}

int main()
{
    string s = "abcabcbb";
    print("lengthOfLongestSubstring");
    print(lengthOfLongestSubstring(s));
    return 1;
}