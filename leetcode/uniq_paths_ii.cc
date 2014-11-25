#include "leetcode.h"

int UniquePathsWithObstacles(vector<vector<int> > &obst) {
  int m = obst.size();
  if (m == 0) {
    return 0;
  }
  int n = obst[0].size();
  if (n == 0) {
    return 0;
  }

  vector<vector<int> > ret;
  for (int i = 0; i < m; ++i) {
    vector<int> row(n, 0);
    ret.push_back(row);
  }

  for (int i = 0; i < m; ++i) {
    if (obst[i][0] == 1) {
      break;
    }
    ret[i][0] = 1;
  }
  for (int j = 0; j < n; ++j) {
    if (obst[0][j] == 1) {
      break;
    }
    ret[0][j] = 1;
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      int tmp = 0;
      if (obst[i - 1][j] == 0) {
        tmp += ret[i - 1][j];
      }
      if (obst[i][j - 1] == 0) {
        tmp += ret[i][j - 1];
      }
      // NOTICE
      if (obst[i][j] == 0) {
        ret[i][j] += tmp;
      }
    }
  }
  return ret[m - 1][n - 1];
}
