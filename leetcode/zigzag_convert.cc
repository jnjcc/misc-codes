#include "leetcode.h"

string ZigZagConvert(const string &s, int rows) {
  int n = s.size();

  // NOTICE: for <"A", 3> / <"AB", 1>
  if (rows >= n || rows == 1) {
    return s;
  }

  string ret = "";
  int diag = rows - 2; // number of elements on diagonal line
  int step = rows + diag;
  for (int i = 0; i < rows; ++i) {
    ret += s.substr(i, 1); // fill in the first full column
    int offset = -i; // offset for elements on the diagonal line
    if (i == rows - 1) {
      offset = i;
    }
    int idx = step + offset;
    while (idx < n) {
      ret += s.substr(idx, 1);
      if (i != 0 && i != rows - 1) {  // for diagonal line elements
        int idx2 = idx + 2 * i;
        if (idx2 < n) {
          ret += s.substr(idx2, 1);
        }
      }
      idx += step;
    }
  }
  return ret;
}
