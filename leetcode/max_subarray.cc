#include "leetcode.h"

int MaxSubArray(int A[], int n) {
  // at least one number
  int max_sum = A[0], cont_sum = A[0]; // sum of contiguous sequence
  for (int i = 1; i < n; ++i) {
    // do we need to restart a contiguous sequence?
    int old_seq = cont_sum + A[i];
    cont_sum = (A[i] > old_seq) ? A[i] : old_seq;
    if (cont_sum > max_sum) {
      max_sum = cont_sum;
    }
  }
  return max_sum;
}
