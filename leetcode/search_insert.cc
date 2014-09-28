#include "leetcode.h"

int SearchInsert(int A[], int n, int target) {
  int ret = 0;
  if (n == 0) {
    return ret;
  }

  int l = 0, r = n - 1;
  while (l < r) {
    int m = (r - l) / 2 + l;
    if (A[m] == target) {
      return m;
    } else if (A[m] < target) {
      ++l;
    } else {
      --r;
    }
  }

  // by now, A[l] == A[r] (thus A[l] == A[m]) && A[l] != target
  if (A[l] < target) {
    return (l + 1);
  } else {
    return l;
  }
}
