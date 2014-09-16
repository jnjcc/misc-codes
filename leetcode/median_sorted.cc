#include "leetcode.h"

// http://leetcode.com/2011/01/find-k-th-smallest-element-in-union-of.html
// NOTICE: That was beautiful...
double KthSmallest(int A[], int m, int B[], int n, int k) {
  if (m > n) {
    return KthSmallest(B, n, A, m, k);
  }
  if (m == 0) {
    return B[k - 1];
  }
  if (k == 1) {
    return min(A[0], B[0]);
  }
  int i = min(m - 1, (k - 1) / 2);
  int j = (k - 1) - i;

  // NOTICE: for A = {1000}, B = {1001}
  if (j == n) {
    if (A[i] > B[j-1]) {
      return A[i];
    } else {
      return KthSmallest(A + i + 1, m - i - 1, B, j, k - i - 1);
    }
  }
  // At most i + j = (k-1) elements below A[i] & B[j]
  if (A[i] < B[j]) {
    if (j > 0 && A[i] > B[j-1]) {
      return A[i];
    } else {
      return KthSmallest(A + i + 1, m - i - 1, B, j, k - i - 1);
    }
  } else if (A[i] > B[j]) {
    if (i > 0 && B[j] > A[i-1]) {
      return B[j];
    } else {
      return KthSmallest(A, i, B + j + 1, n - j - 1, k - j -1);
    }
  } else {
    return A[i];
  }
}

double FindMedianSortedArrays(int A[], int m, int B[], int n) {
  if ((m + n) % 2) {
    return KthSmallest(A, m, B, n, (m + n + 1) / 2);
  } else {
    int low = (m + n) / 2;
    return 0.5 * KthSmallest(A, m, B, n, low) +
        0.5 * KthSmallest(A, m, B, n, low + 1);
  }
}
