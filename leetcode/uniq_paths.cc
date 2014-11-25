#include "leetcode.h"

int UniquePaths(int m, int n) {
  if (m <= 0 || n <= 0) {
    return 0;
  }

  int **bk = new int*[m]; // bookkeeping
  for (int i = 0; i < m; ++i) {
    bk[i] = new int[n];
  }

  for (int i = 0; i < m; ++i) {
    bk[i][0] = 1;
  }
  for (int j = 0; j < n; ++j) {
    bk[0][j] = 1;
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      bk[i][j] = bk[i - 1][j] + bk[i][j - 1];
    }
  }

  int ret = bk[m - 1][n - 1];

  for (int i = 0; i < m; ++i) {
    delete bk[i];
  }
  delete bk;
  return ret;
}
