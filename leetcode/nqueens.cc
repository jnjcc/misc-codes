#include "leetcode.h"

bool ValidQueen(int i, int j, int n, vector<string> &board) {
  int k;
  for (k = i; k >= 0; --k) {
    if (board[k][j] == 'Q') {
      return false;
    }
  }
  for (k = j; k >= 0; --k) {
    if (board[i][k] == 'Q') {
      return false;
    }
  }

  int k1 = i, k2 = j;
  while (k1 >= 0 && k2 >= 0) {
    if (board[k1][k2] == 'Q') {
      return false;
    }
    --k1; --k2;
  }
  k1 = i, k2 = j;
  while (k1 >= 0 && k2 < n) {
    if (board[k1][k2] == 'Q') {
      return false;
    }
    --k1; ++k2;
  }
  return true;
}
void PutIthQueen(int i, int n, vector<string> &board,
    vector<vector<string> > &sol) {
  if (i >= n) {
    sol.push_back(board);
    return;
  }
  string col(n, '.');
  board.push_back(col);
  for (int j = 0; j < n; ++j) {
    if (ValidQueen(i, j, n, board)) {
      board[i][j] = 'Q';
      PutIthQueen(i + 1, n, board, sol);
      board[i][j] = '.';
    }
  }
  board.pop_back();
}

vector<vector<string> > SolveNQueens(int n) {
  vector<vector<string> > ret;
  vector<string> board;
  PutIthQueen(0, n, board, ret);
  return ret;
}
