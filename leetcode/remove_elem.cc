#include "leetcode.h"

int RemoveElement(int A[], int n, int elem) {
  int idx = -1;
  for (int i = 0; i < n; ++i) {
    if (A[i] != elem) {
      A[++idx] = A[i];
    }
  }
  return (idx + 1);
}
