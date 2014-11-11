#include "leetcode.h"

void RotateCopy(vector<vector<int> > &matrix) {
  int n = matrix.size();
  vector<int> row(n, 0);
  vector<vector<int> > copy;
  for (int i = 0; i < n; ++i) {
    copy.push_back(row);
  }
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      copy[i][j] = matrix[n - 1 - j][i];
    }
  }
  matrix = copy;
}

void RotateInPlace(vector<vector<int> > &matrix) {
  int n = matrix.size();
  int rbeg = 0, rend = n - 1;  // row beg, row end
  int cbeg = 0, cend = n - 1;  // col beg, col end
  while (rbeg < rend) {
    for (int j = cbeg; j < cend; ++j) {
      int save = matrix[rbeg][j];
      matrix[rbeg][j] = matrix[n - 1 -j][cbeg];
      matrix[n - 1 - j][cbeg] = matrix[rend][n - j - 1];
      matrix[rend][n - j - 1] = matrix[j][cend];
      matrix[j][cend] = save;
    }
    ++rbeg; --rend;
    ++cbeg; --cend;
  }
}

void Rotate(vector<vector<int> > &matrix) {
  RotateInPlace(matrix);
}
