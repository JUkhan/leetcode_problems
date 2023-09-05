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

vector<string> backtrack(string s, int size, vector<char> m = vector<char>())
{
    if (s.size() == 0)
        return vector<string>();
    
    vector<string> res;
    
    for (int i = 0; i < s.size(); i++)
    {
        m.push_back(s[i]);

        auto t = backtrack(s.substr(i + 1) + s.substr(0, i),size, m);
        if (m.size() == size)
            res.push_back(string(m.begin(), m.end()));
        m.pop_back();

        res.insert(res.end(), t.begin(), t.end());
    }
    return res;
}

int main()
{
    
    vector<string> res = backtrack("ABCD", 4);
    print(res);

    print("checkInclusion");
    print(checkInclusion("ab", "sdadbadf"));
}