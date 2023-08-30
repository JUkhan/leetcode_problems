// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

#include "../print.h"

bool isPalindrome_old(string s)
{

    auto it = remove_if(s.begin(), s.end(), [](char ch)
                        { return !isalnum(ch) || ch == ' '; });
    s.erase(it, s.end());
    string s1="";
    transform(s.begin(), s.end(), s1.begin(), [](char ch)
              { return isupper(ch) ? tolower(ch) : ch; });

    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s1[l] != s1[r])
            return false;
        l++;
        r--;
    }

    return true;
}

/**
 * Checks whether the given string is a palindrome after removing non-alphanumeric characters and spaces.
 * 
 * This function determines if the input string 's' is a palindrome after removing any non-alphanumeric
 * characters and spaces. The comparison is case-insensitive.
 * 
 * @param s The input string to be checked.
 * @return True if the string is a palindrome, false otherwise.
 */
bool isPalindrome(string s)
{
    auto it = remove_if(s.begin(), s.end(), [](char ch)
                        { return !isalnum(ch) || ch == ' '; });
    s.erase(it, s.end());

    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (tolower(s[l]) != tolower(s[r]))
            return false;
        l++;
        r--;
    }

    return true;
}

bool isPalindrome2(string s)
{
    
    auto it = remove_if(s.begin(), s.end(), [](char ch)
                        { return !isalnum(ch) || ch == ' '; });
    s.erase(it, s.end());
    vector<char> m(s.size());
    transform(s.begin(), s.end(),m.begin(), [](char ch){return isupper(ch)?tolower(ch):ch;});
    string ms(m.begin(), m.end());
    print(ms);
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (tolower(s[l]) != tolower(s[r]))
            return false;
        l++;
        r--;
    }

    return true;
}

void run()
{
    string s = "A man, a plan, a canal: Panama";
    bool res = isPalindrome(s);
    print("isPalindrome:");
    print(res);
}