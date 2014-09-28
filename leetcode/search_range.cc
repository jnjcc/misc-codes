#include "leetcode.h"

vector<int> SearchRange(int A[], int n, int target) {
  vector<int> ret;
  int l = 0, r = n - 1;
  int m = -1;
  while (l <= r) {
    m = (r - l) / 2 + l;
    if (A[m] == target) {
      int lower = m, upper = m;
      while (lower > 0 && A[lower - 1] == A[m]) {
        --lower;
      }
      while (upper < r && A[upper + 1] == A[m]) {
        ++upper;
      }
      ret.push_back(lower);
      ret.push_back(upper);
      return ret;
    } else if (A[m] < target) {
      ++l;
    } else {
      --r;
    }
  }
  ret.push_back(-1);
  ret.push_back(-1);
  return ret;
}
