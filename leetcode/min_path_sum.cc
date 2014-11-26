#include "leetcode.h"

int MinPathSum(vector<vector<int> > &grid) {
  int m = grid.size();
  if (m == 0) {
    return 0;
  }
  int n = grid[0].size();
  if (n == 0) {
    return 0;
  }

  vector<vector<int> > ret;
  for (int i = 0; i < m; ++i) {
    vector<int> row(n, 0);
    ret.push_back(row);
  }

  ret[0][0] = grid[0][0];
  for (int i = 1; i < m; ++i) {
    ret[i][0] = ret[i - 1][0] + grid[i][0];
  }
  for (int j = 1; j < n; ++j) {
    ret[0][j] = ret[0][j - 1] + grid[0][j];
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      ret[i][j] = grid[i][j];
      ret[i][j] += min(ret[i - 1][j], ret[i][j - 1]);
    }
  }
  return ret[m - 1][n - 1];
}
