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
#include<tuple>
#include<regex>
#include<climits>
#include<stack>
#include <functional>
#include <sstream>


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

template<typename T>
void print(stack<T> st)
{

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout << endl;
}

template<typename T>
void print(unordered_set<T> &vec)
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

template<typename T>
void print(T str){
    cout<<endl<<str<<endl;
}

template<typename T, typename N>
void print(unordered_map<T, N> &map){
    cout<<endl;
    for(auto it : map)
        cout<<it.first<<":"<<it.second<<", ";
    cout<<endl;
}