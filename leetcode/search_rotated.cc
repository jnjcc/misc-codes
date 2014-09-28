#include "leetcode.h"

int BinarySearch(int A[], int l, int r, int target) {
  if (l > r) {
    return -1;
  }

  int m = (r - l) / 2 + l;
  if (A[m] == target) {
    return m;
  }

  if (A[m] < A[r]) {
    if (A[m] < target && target <= A[r]) {
      return BinarySearch(A, m + 1, r, target);
    } else {
      return BinarySearch(A, l, m - 1, target);
    }
  } else if (A[m] > A[r]) {
    if (A[l] <= target && target < A[m]) {
      return BinarySearch(A, l, m - 1, target);
    } else {
      return BinarySearch(A, m + 1, r, target);
    }
  } else {
    return BinarySearch(A, l, r - 1, target);
  }
}

int SearchRotated(int A[], int n, int target) {
  return BinarySearch(A, 0, n-1, target);
}
