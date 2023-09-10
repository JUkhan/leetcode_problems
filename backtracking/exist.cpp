#include "../print.h"

/*
79. Word Search
https://leetcode.com/problems/word-search/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
Input: board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = 'ABCCED'
Output: true
*/
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        rSize = board.size();
        cSize = board[0].size();
        for (int r = 0; r < rSize; r++)
        {
            for (int c = 0; c < cSize; c++)
            {
                
                if(checkWord(board, r, c, 0, word))return true;
                
            }
        }
        return false;
    }

private:
    int rSize, cSize;
    bool checkWord(vector<vector<char>> &board, int r, int c, int i, string word)
    {

        if (r >= rSize || r < 0 || c >= cSize || c < 0|| board[r][c]!= word[i])
            return false;
        if(i==word.size()-1)return true;
        board[r][c]-1;
        if(checkWord(board, r, c + 1, i+1, word)
        ||checkWord(board, r, c - 1, i+1, word)
        ||checkWord(board, r + 1, c, i+1, word)
        ||checkWord(board, r - 1, c, i+1, word))return true;
        board[r][c]+1;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution s;
    auto res = s.exist(board, word);
    print(res);
    return 0;
}
