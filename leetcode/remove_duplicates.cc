#include "leetcode.h"

int RemoveDuplicates(int A[], int n) {
  if (n <= 0) {
    return 0;
  }
  int idx = 0;
  for (int i = 1; i < n; ++i) {
    if (A[i] == A[idx]) {
      continue;
    } else {
      A[++idx] = A[i];
    }
  }
  return (idx + 1);
}
