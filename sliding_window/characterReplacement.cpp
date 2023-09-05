#include "../print.h"

// 424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/

/**
 * You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
 *
 * Return the length of the longest substring containing the same letter you can get after performing the above operations.
 */
int characterReplacement(string s, int k)
{
    int const N = s.size();
    vector<int> count(26);
    int l = 0, r = 0, result = 0, maxCount = 0;
    while (r < N)
    {
        count[s[r] - 'A']++;
        maxCount = max(maxCount, count[s[r] - 'A']);
        if (r - l + 1 > maxCount + k)
        {
            count[s[l] - 'A']--;
            l++;
        }
        result = max(result, r - l + 1);
        r++;
    }
    return result;
}



int main()
{
    print("characterReplacement");
    print(characterReplacement("BAAAB", 2));   // 4
    print(characterReplacement("AABABBA", 1)); // 4
    print(characterReplacement("BAAAB", 2));   // 5
    print(characterReplacement("ABCDE", 1));   // 2
    print(characterReplacement("ABBB", 2));    // 4
    print(characterReplacement("ABAA", 0));    // 2
    // output: 2

    return 0;
}