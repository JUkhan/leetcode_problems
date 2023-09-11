#include "../print.h"

// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

/**
 * Checks whether two given strings are anagrams of each other.
 *
 * This function determines if two strings are anagrams by comparing their character frequencies.
 * Anagrams are strings that can be rearranged to form the same string.
 *
 * @param s The first string to be checked.
 * @param t The second string to be checked.
 * @return True if the strings are anagrams, false otherwise.
 */
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> smap, tmap;
    for (int i = 0; i < s.size(); i++)
    {
        smap[s[i]]++;
        tmap[t[i]]++;
    }

    for (char k : s)
    {
        if (smap[k] != tmap[k])
            return false;
    }
    return true;
}

int main()
{
    const bool res = isAnagram("anagram", "nagaram");
    cout << "isAnagram: " << res << endl;
    return 0;
}