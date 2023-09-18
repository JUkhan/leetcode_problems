from typing import List


# 496. Next Greater Element I
# https://leetcode.com/problems/next-greater-element-i/description/

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        map = {n: i for i, n in enumerate(nums1)}
        res = [-1] * len(nums1)
        st = []
        for n in nums2:
            while st and n > st[-1]:
                k = st.pop()
                index = map[k]
                res[index] = n
            if n in map:
                st.append(n)

        return res



