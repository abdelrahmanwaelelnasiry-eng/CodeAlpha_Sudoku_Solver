#include <iostream>
using namespace std;

const int SIZE = 9;

// التحقق من وجود الرقم في الصف
bool isInRow(int grid[SIZE][SIZE], int row, int num)
{
    for (int col = 0; col < SIZE; col++)
    {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

// التحقق من وجود الرقم في العمود
bool isInCol(int grid[SIZE][SIZE], int col, int num)
{
    for (int row = 0; row < SIZE; row++)
    {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

// التحقق من وجود الرقم في المربع 3×3
bool isInBox(int grid[SIZE][SIZE], int startRow, int startCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + startRow][col + startCol] == num)
                return true;
        }
    }
    return false;
}

// التحقق من إمكانية وضع الرقم
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{
    return !isInRow(grid, row, num) &&
           !isInCol(grid, col, num) &&
           !isInBox(grid, row - row % 3, col - col % 3, num);
}

// البحث عن خانة فارغة
bool findEmpty(int grid[SIZE][SIZE], int &row, int &col)
{
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

// حل السودوكو باستخدام Backtracking
bool solveSudoku(int grid[SIZE][SIZE])
{
    int row, col;

    if (!findEmpty(grid, row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

// طباعة الجدول
void printGrid(int grid[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int grid[SIZE][SIZE];

    cout << "Enter Sudoku (0 for empty cells):\n";

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> grid[i][j];
        }
    }

    if (solveSudoku(grid))
    {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}