from collections import defaultdict
from typing import List
# 36. Valid Sudoku
# https://leetcode.com/problems/valid-sudoku/description/

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(set)
        cols = defaultdict(set)
        squares = defaultdict(set)
        for r in range(9):
            for c in range(9):
                num = board[r][c]
                if num == '.': continue
                if (
                        num in rows[r]
                        or num in cols[c]
                        or num in squares[(r // 3, c // 3)]
                ):
                    return False
                rows[r].add(num)
                cols[c].add(num)
                squares[(r // 3, c // 3)].add(num)
        return True
