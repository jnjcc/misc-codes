#include "leetcode.h"

// NOTICE
int FirstMissingPositive(int A[], int n) {
  int tmp;
  for (int i = 0; i < n; ++i) {
    while (A[i] != i + 1) {
      // try putting A[i] to the right place
      // DEST: where A[i] should have been
      int dest = A[i] - 1;
      if (A[i] <= 0 || A[i] > n || A[i] == A[dest]) {
        break;
      }
      tmp = A[i];
      A[i] = A[dest];
      A[dest] = tmp;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (A[i] != i + 1) {
      return (i + 1);
    }
  }
  return (n + 1);
}
