#include "leetcode.h"

vector<vector<int> > GenerateMatrix(int n) {
  vector<vector<int> > ret;
  if (n <= 0) {
    return ret;
  }

  int num = n * n;
  for (int i = 0; i < n; ++i) {
    vector<int> vec(n, 0);
    ret.push_back(vec);
  }

  int rs = 0, re = n - 1; // row start, row end
  int cs = 0, ce = n - 1; // column start, column end
  int cur = 1;
  while (rs < re && cs < ce) {
    for (int j = cs; j < ce; ++j) {
      ret[rs][j] = cur++;
    }
    for (int i = rs; i < re; ++i) {
      ret[i][ce] = cur++;
    }
    for (int j = ce; j > cs; --j) {
      ret[re][j] = cur++;
    }
    for (int i = re; i > rs; --i) {
      ret[i][cs] = cur++;
    }
    ++rs; ++cs;
    --re; --ce;
  }
  if (rs == re) {
    for (int j = cs; j <= ce; ++j) {
      ret[rs][j] = cur++;
    }
  } else if (cs == ce) {
    for (int i = rs; i <= re; ++i) {
      ret[i][cs] = cur++;
    }
  }
  return ret;
}
