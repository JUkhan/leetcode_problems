from collections import defaultdict
from typing import List


def fib(n: int) -> int:
    memo = {}
    for i in range(1, n + 1):
        if i <= 2:
            memo[i] = i
        else:
            memo[i] = memo[i - 1] + memo[i - 2]
    return memo[n]


print(fib(5))


def min_and_ignore(a: int, b: int) -> int:
    if a is None:
        return b
    if b is None:
        return a
    return min(a, b)


def diff_ways(coins: List[int], target: int) -> int:
    memo = defaultdict(lambda _: 0)
    memo[0] = 1
    for i in range(1, target + 1):
        memo[i] = 0
        for n in coins:
            sub_problem = i - n
            if sub_problem < 0:
                continue
            memo[i] = memo[i] + memo[sub_problem]
    print(memo)
    return memo[target]


print(diff_ways([1, 4, 5], 5))


def minimum_coin(coins: List[int], target: int) -> int:
    memo = {}
    memo[0] = 0
    for i in range(1, target + 1):
        for coin in coins:
            sub_problem = i - coin
            if sub_problem < 0:
                continue
            memo[i] = min_and_ignore(memo.get(i), 1 + memo.get(sub_problem))
    print(memo)
    return memo[target]


print(minimum_coin([1, 4, 5], 5))


def rabit_move(r: int, c: int):
    memo = {}
    for row in range(r):
        memo[(row, 0)] = 1
    for col in range(c):
        memo[(0, col)] = 1

    for r1 in range(1, r):
        for c1 in range(1, c):
            memo[(r1, c1)] = memo[(r1 - 1, c1)] + memo[(r1, c1 - 1)]
    print(memo)
    return memo[(r - 1, c - 1)]


print(rabit_move(3, 3))


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            memo_row = set()
            memo_col = set()
            for j in range(9):
                if board[i][j] != '.': 
                    if board[i][j] in memo_row:
                        return False
                    else:
                        memo_row.add(board[i][j])
                if i==3:
                    print(i)
                if board[j][i] == '.': continue
                if board[j][i] in memo_col:
                    return False
                else:
                    memo_col.add(board[j][i])
            if i==3:
              print(memo_col)

        xp = [True, True, True]
        for i in range(9):
            if xp[i // 3]:
                memo = [set(), set(), set()]
                xp[i // 3] = False
            for j in range(9):
                if board[j][i] == '.': continue
                index = j // 3
                if board[j][i] in memo[index]:
                    return False
                else:
                    memo[index].add(board[j][i])
        return True


mm = [
    [".", ".", "4", ".", ".", ".", "6", "3", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
    ["5", ".", ".", ".", ".", ".", ".", "9", "."],
    [".", ".", ".", "5", "6", ".", ".", ".", "."],
    ["4", ".", "3", ".", ".", ".", ".", ".", "1"],
    [".", ".", ".", "7", ".", ".", ".", ".", "."],
    [".", ".", ".", "5", ".", ".", ".", ".", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."]]
s = Solution()
print(s.isValidSudoku(mm))
