#include "leetcode.h"

vector<int> SpiralOrder(vector<vector<int> > &matrix) {
  vector<int> ret;
  int m = matrix.size();  // row
  if (m <= 0) {
    return ret;
  }
  int n = matrix[0].size();  // column

  int ms = 0, ns = 0;  // row start, column start
  int me = m - 1, ne = n - 1;  // row end, column end

  int i, j;
  while (ms < me && ns < ne) {
    i = ms, j = ns;

    while (j < ne) {  // upper-row
      ret.push_back(matrix[i][j]);
      ++j;
    }
    while (i < me) {  // right-column
      ret.push_back(matrix[i][j]);
      ++i;
    }
    while (j > ns) {
      ret.push_back(matrix[i][j]);
      --j;
    }
    while (i > ms) {
      ret.push_back(matrix[i][j]);
      --i;
    }
    ++ms; ++ns;
    --me; --ne;
  }
  // NOTICE: check if both conditions reached end
  if (ms == me) {
    for (j = ns; j <= ne; ++j) {
      ret.push_back(matrix[ms][j]);
    }
  } else if (ns == ne) {
    for (i = ms; i <= me; ++i) {
      ret.push_back(matrix[i][ns]);
    }
  }
  return ret;
}
