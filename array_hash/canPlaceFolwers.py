from typing import List


def hasLeft(arr: List[int], index: int):
    if index < 0: return True
    return True if arr[index] == 0 else False


def hasRight(arr: List[int], index: int):
    if index >= len(arr): return True
    return True if arr[index] == 0 else False


class Solution:

    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        l = len(flowerbed)
        for i in range(len(flowerbed)):
            if hasLeft(flowerbed, i - 1) and flowerbed[i] == 0 and hasRight(flowerbed, i + 1):
                flowerbed[i] = 1
                n -= 1
        # print(flowerbed)
        return n <= 0


s = Solution()
print(s.canPlaceFlowers([0, 1, 0, 0, 0, 1], 2))
