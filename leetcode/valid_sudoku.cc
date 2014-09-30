#include "leetcode.h"

bool IsValidSubBox(const vector<vector<char> > &board, int x, int y) {
  int mask = 0;
  for (int i = x; i < x + 3; ++i) {
    for (int j = y; j < y + 3; ++j) {
      if (board[i][j] == '.') {
        continue;
      }
      int shift = board[i][j] - '0';
      if (mask & (1 << shift)) {
        return false;
      }
      mask |= (1 << shift);
    }
  }
  return true;
}

bool IsValidSudoku(const vector<vector<char> > &board) {
  for (int i = 0; i < 9; ++i) {
    // valid row?
    int mask = 0;
    for (int j = 0; j < 9; ++j) {
      if (board[i][j] == '.') {
        continue;
      }
      int shift = board[i][j] - '0';
      if (mask & (1 << shift)) {
        return false;
      }
      mask |= (1 << shift);
    }
  }

  for (int j = 0; j < 9; ++j) {
    // valid col?
    int mask = 0;
    for (int i = 0; i < 9; ++i) {
      if (board[i][j] == '.') {
        continue;
      }
      int shift = board[i][j] - '0';
      if (mask & (1 << shift)) {
        return false;
      }
      mask |= (1 << shift);
    }
  }

  for (int x = 0; x < 9; x += 3) {
    for (int y = 0; y < 9; y += 3) {
      if (!IsValidSubBox(board, x, y)) {
        return false;
      }
    }
  }

  return true;
}
