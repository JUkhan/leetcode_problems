#include "../print.h"

//49. Group Anagrams
//https://leetcode.com/problems/group-anagrams/

/**
 * Groups anagrams from the input vector of strings into separate groups.
 * 
 * This function groups anagrams from the 'strs' vector into separate groups.
 * It uses an unordered map to keep track of anagrams and their corresponding group indices.
 * The function sorts each word to identify its anagram and then adds it to the appropriate group.
 * 
 * @param strs The input vector of strings containing potential anagrams.
 * @return A vector of vectors where each inner vector contains a group of anagrams.
 */
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    unordered_map<string, int> map;
    int c = 0;
    for (string k : strs)
    {
        string m = k;
        sort(k.begin(), k.end());
        if (map.find(k) != map.end())
        {
            res[map[k]].push_back(m);
        }
        else
        {
            // vector<string> t{m};
            res.push_back(vector<string>{m});
            map[k] = c++;
        }
    }
    return res;
}

void run(){
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    auto res=groupAnagrams(strs);
    cout<<"groupAnagrams:"<<endl;
    print(res);
}