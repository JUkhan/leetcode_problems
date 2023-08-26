#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;

template<typename T>
void print(vector<T> &vec)
{
    for (auto a : vec)
    {
        cout << a << " ";
    }
    cout << endl;
}


template<typename T, typename V>
void print(vector<pair<T, V>> &vec)
{
    for (auto &p : vec)
    {
        cout << p.first << " : " << p.second << ", ";
    }
    cout << endl;
}

template<typename T>
void print(vector<vector<T>> &vec)
{
    for (auto v : vec)
    {
        for(auto a:v){
            cout << a << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print(string str){
    cout<<endl<<str<<endl;
}