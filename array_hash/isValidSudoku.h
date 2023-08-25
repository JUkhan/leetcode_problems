#include "../print.h"

// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/description/

bool isValidDigit(char ch)
{
    return ch >= 48 && ch <= 57;
}

/**
 * Checks whether the given Sudoku board is a valid Sudoku configuration.
 *
 * This function checks whether the provided Sudoku board adheres to the rules of Sudoku.
 * It ensures that no duplicate digits appear in rows, columns, or 3x3 subgrids.
 *
 * @param board The Sudoku board as a 2D vector of characters.
 * @return True if the Sudoku board is valid, false otherwise.
 */
bool isValidSudoku_old(vector<vector<char>> &board)
{
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> subset(9);

    for (int i = 0; i < 9; i++)
    {
        int cv = (i / 3) * 3;
        for (int j = 0; j < 9; j++)
        {
            char ch = board[i][j];
            if (ch == '.')
                continue;
            // if(!isValidDigit(ch)) return false;
            // row check
            if (rows[i].count(ch))
                return false;
            rows[i].insert(ch);
            // col check
            if (cols[j].count(ch))
                return false;
            cols[j].insert(ch);
            // check subset wise
            int index = cv + (j / 3);
            if (subset[index].count(ch))
                return false;
            subset[index].insert(ch);
        }
    }
    return true;
}

/**
 * Checks whether the given Sudoku board is a valid Sudoku configuration.
 *
 * This function checks whether the provided Sudoku board adheres to the rules of Sudoku.
 * It ensures that no duplicate digits appear in rows, columns, or 3x3 subgrids.
 *
 * @param board The Sudoku board as a 2D vector of characters.
 * @return True if the Sudoku board is valid, false otherwise.
 */
bool isValidSudoku(vector<vector<char>> &board)
{
    const int size = 9;
    bool rows[size][size] = {false};
    bool cols[size][size] = {false};
    bool subset[size][size] = {false};

    for (int i = 0; i < size; i++)
    {
        int cv = (i / 3) * 3;
        for (int j = 0; j < size; j++)
        {
            char ch = board[i][j];
            if (ch == '.')
                continue;

            int index = ch - '0' - 1;
            int subIndex = cv + (j / 3);
            if (rows[i][index] || cols[j][index] || subset[subIndex][index])
            {
                return false;
            }
            rows[i][index] = true;
            cols[j][index] = true;
            subset[subIndex][index] = true;
        }
    }
    return true;
}

void run()
{
    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << "isValidSudoku:" << isValidSudoku(board) << endl;
}