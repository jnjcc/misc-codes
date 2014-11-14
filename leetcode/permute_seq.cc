#include "leetcode.h"

string GetPermutation(int n, int k) {
  string ret;
  if (k <= 0) {
    return ret;
  }
  int fact = 1, m = 1;
  while (m <= n) {
    fact *= m;
    ++m;
  }
  if (k > fact) {
    return ret;
  }

  fact /= n;

  vector<bool> used(n, false);
  int idx = 0; // index of the first non-used number
  const int kIdxSize = 2;
  char pos[kIdxSize];
  for (int i = 1; i <= n; ++i) {
    if (k <= fact) { // the following (n-i) numbers are enough
      snprintf(pos, kIdxSize, "%d", idx + 1);
      ret += pos;
      used[idx] = true;
    } else {
      // how many (n-i)! sequences do we need _before_ this sequence
      int offset = (k + fact - 1) / fact - 1;
      // how many sequences left with current leading number
      k -= offset * fact;
      int cur_off = 0;
      for (int j = idx; j < n; ++j) {
        if (!used[j]) {
          if (cur_off == offset) {
            snprintf(pos, kIdxSize, "%d", j + 1);
            ret += pos;
            used[j] = true;
            break;
          }
          ++cur_off;
        }
      }
    }

    // move to the first non-used number
    while (idx < n && used[idx]) {
      ++idx;
    }
    if (i < n) {
      fact /= (n - i);
    }
  }
  return ret;
}
