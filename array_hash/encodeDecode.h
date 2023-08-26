#include "../print.h"

// 659. Encode and Decode Strings

string encode(vector<string> &strs)
{

    return accumulate(strs.begin(), strs.end(), (string) "", [](string res, string word)
                      { return res + to_string(word.size()) + "#" + word; });
}

vector<string> decode(string &str)
{
    int i = 0;
    string digit = "";
    vector<string> res;
    while (i < str.size())
    {
        if (str[i] == '#')
        {
            int l = stoi(digit);
            res.push_back(str.substr(i + 1, l));
            i +=  l;
            digit = "";
        }
        else
            digit += str[i];
        i++;
    }
    return res;
}

void run()
{
    vector<string> words{"I", "Love", "You"};
    print("original:");
    print(words);
    auto encoded = encode(words);
    print("after encode:");
    print(encoded);
    print("after decode:");
    auto res=decode(encoded);
    print(res);
}