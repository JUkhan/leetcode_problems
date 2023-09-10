#include "../print.h"

bool checkInclusion(string s1, string s2)
{
    vector<int> count(26);
    auto isPermutation = [](vector<int> arr)
    {
        return all_of(arr.begin(), arr.end(), [](int a)
                      { return a == 0; });
    };
    for (int i = 0; i < s1.size(); i++)
    {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    if (isPermutation(count))
        return true;
    int l = 0;
    for (int r = s1.size(); r < s2.size(); r++)
    {
        count[s2[l] - 'a']++;
        count[s2[r] - 'a']--;
        if (isPermutation(count))
            return true;
        l++;
    }
    return false;
}



int main()
{
    print("checkInclusion");
    print(checkInclusion("ab", "sdadbadf"));
}