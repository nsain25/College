#include <iostream>
using namespace std;

#define N 8

int board[N][N];

void printSolution(int n) {
    cout << "--------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "| ";
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "--------------------------" << endl;
}

bool isSafe(int row, int col, int n) {
    int i, j;
  
    // Check the column on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }
  
    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
  
    // Check lower left diagonal
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) return false;
    }
  
    return true;
}

bool solveNQueens(int col, int n) {
    if (col >= n) return true; // All queens are placed successfully
  
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1; // Place queen
            
            if (solveNQueens(col + 1, n)) return true; // Recur to place the rest of the queens
            
            board[i][col] = 0; // If placing queen doesn't lead to a solution, backtrack
        }
    }
  
    return false; // If queen can't be placed in any row, return false
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0; // Initialize board with all zeros
        }
    }
  
    if (solveNQueens (0, n)) {
        printSolution(n);
    } else {
        cout << "No solution found!" << endl;
    }
     cout << "NAME: NANDINI SAIN" << endl;
    cout << "ENROLLMENT NO. : A2305221060" << endl;
    return 0;
}
