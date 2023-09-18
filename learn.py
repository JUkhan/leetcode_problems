from typing import List
import heapq
from collections import deque, defaultdict, namedtuple, OrderedDict, Counter
from sortedcontainers import sortedlist


def sets_operation():
    s = {"a", "c"}
    s = set([1, 2, 3])
    t = set([1, 2, 3, 7])

    print(t.difference(s, ))
    print(s.intersection(t))
    print(s.issubset(t))
    print(s.union(t))
    print(s.isdisjoint(t))


# sets_operation()


def tuples_operation():
    a, b = (1, 2)
    t = (1, 2, 3)
    print(a, b, t[0], t[2])
    person = namedtuple('person', ['name', 'age'])
    a = person('jasim', 23)
    print(a)
    print(a[0])
    print(a.name, a.age)


# tuples_operation()


def map_operation():
    m = {}
    m['hello'] = "bob";
    print(m.setdefault("moses", "khan"))
    m.pop("hello")
    print(m)
    m = OrderedDict()
    m['a'] = 101
    m['m'] = 103
    m['b'] = 2
    for k, v in m.items():
        print(k, v)
    dd = defaultdict(lambda: 'no data')
    print(dd['key'])


# map_operation()
def double_ended_queue():
    dq = deque([1, 2, 3], maxlen=3)
    print(dq)
    dq.rotate(-2)
    print(dq)
    print(dq.pop())


def priority_queue():
    d = [4, 6, 1, 9, 5]
    heapq.heapify(d)
    print(d)
    print(heapq.heappop(d))
    heapq.heappush(d, 7)
    print(d)
    print(heapq.nsmallest(3, [3, 6, 1, 9, 2]))
    print(heapq.nlargest(2, d, key=lambda a: a))


def sort_data():
    d = [4, 2, 5, 1, 8]
    d *= 3
    d.sort(key=lambda a: a, reverse=True)
    print(sorted(d))
    print(d)


def b_search(arr: List[int], t: int):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] < t:
            low = mid + 1
        elif arr[mid] > t:
            high = mid - 1
        else:
            return mid

    return -1


def nextGreaterElement(nums1: List[int], nums2: List[int]) -> List[int]:
    map = {}
    res = []
    for i, v in enumerate(nums2):
        map[v] = i
    for v in nums1:
        index = map[v]
        res.append(nums2[index + 1] if index + 1 < len(nums2)
                                       and nums2[index + 1] > v else -1)
    return res


def str_operation():
    s = 'A'

    num = str(1234)
    nums = ["jasim", "khan", 'bengali']
    print(".".join(nums))
    print(s * 3, ord('A'), num * 2)

    s = 'ABC'
    for i in range(len(s) - 1, -1, -1):
        print(i)
    print("jasim uddin khan".split(" "))
    for c in Counter(["tumi", "tumi", "lot"]).values(): print(c)
    print([2, 2] == [1, 2])


# str_operation()
def topKFrequent(nums: List[int], k: int) -> List[int]:
    map = Counter(nums)
    arr = [[] for _ in range(len(nums) + 1)]
    for num, freq in map.items():
        print((num, freq))
        arr[freq].append(num)
    print(arr)
    res = []
    for i in range(len(arr) - 1, -1, -1):
        if k <= 0: return res
        if arr[i]:
            res.extend(arr[i])
            k -= len(arr[i])
    return res
print(topKFrequent([1,1,1,2,2,3],2))