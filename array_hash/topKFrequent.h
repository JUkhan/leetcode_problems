#include "../print.h"

// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

using namespace std;
struct kvo
{
    int key, val;
};

class kv_compare
{

public:
    bool operator()(kvo a, kvo b)
    {
        return a.val < a.val;
    }
};

// template<int k, int v>
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> topKFrequent_old(vector<int> &nums, int k)
{
    priority_queue<kvo, vector<kvo>, kv_compare> pq;
    unordered_map<int, int> map;
    for (int n : nums)
    {
        map[n]++;
    }
    vector<pair<int, int>> kv;
    for (auto &p : map)
    {
        kv.push_back({p.first, p.second});
        pq.push({p.first, p.second});
    }
    sort(kv.begin(), kv.end(), compare);
    vector<int> mm(k);
    // transform(kv.begin(), kv.begin() + k, mm.begin(), [](pair<int, int> p)  { return p.first; });
    for (int i = 0; i < k; i++)
    {
        mm[i] = pq.top().key;
        pq.pop();
    }
    return mm;
}
// O(klog(n))
vector<int> topKFrequent_old_old(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    for (auto n : nums)
    {
        m[n]++;
    }
    for (auto p : m)
    {
        pq.push({p.second, p.first});
    }
    vector<int> res(k);
    for (int i = 0; i < k; i++)
    {
        res[i] = pq.top().second;
        pq.pop();
    }
    return res;
}
// O(n)

/**
 * Finds the top k most frequent elements from the given vector of integers.
 *
 * This function determines the k most frequent elements in the input vector 'nums'.
 * It uses a hash map to count the frequency of each element, and then groups the
 * elements based on their frequencies using a bucket sort-like approach.
 *
 * @param nums The input vector of integers.
 * @param k The number of most frequent elements to be retrieved.
 * @return A vector containing the top k most frequent elements.
 */
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    int n = nums.size() + 1;
    vector<vector<int>> store(n);
    for (auto n : nums)
    {
        m[n]++;
    }
    for (auto &p : m)
    {
        store[p.second].push_back(p.first);
    }
    vector<int> res;
    for (auto it = store.rbegin(); it != store.rend(); ++it)
    {
        if (k <= 0)
            break;
        if (it->size())
        {
            k -= it->size();
            res.insert(res.begin(), it->begin(), it->end());
        }
    }
    return res;
}

void run()
{
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;
    auto res = topKFrequent(nums, k);
    cout << "topKFrequent:" << endl;
    print(res);
}