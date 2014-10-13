#include "leetcode.h"

enum IntervalType {
  OPEN = 0,
  LEFT_OPEN, // the right end point is fixed
  RIGHT_OPEN, // the left end point is fixed
  CLOSED
};

int TrapInterval(int A[], int s, int e, int type) {
  int ret = 0;
  if (e <= s + 1) {
    return ret;
  } else if (type == CLOSED) {
    ret = min(A[s], A[e]) * (e - s - 1);
    for (int j = s + 1; j < e; ++j) {
      ret -= A[j];
    }
    return ret;
  }

  int max_idx = -1, max_height = -1;
  for (int i = s + 1; i < e; ++i) {
    if (max_height < A[i]) {
      max_height = A[i];
      max_idx = i;
    }
  }

  switch (type) {
    case OPEN:
      if (A[s] > A[max_idx]) {
        max_idx = s;
      }
      if (A[e] > A[max_idx]) {
        max_idx = e;
      }
      return TrapInterval(A, s, max_idx, LEFT_OPEN) +
             TrapInterval(A, max_idx, e, RIGHT_OPEN);

    case LEFT_OPEN:
      max_idx = (A[max_idx] > A[s]) ? max_idx : s;
      return TrapInterval(A, s, max_idx, LEFT_OPEN) +
             TrapInterval(A, max_idx, e, CLOSED);

    case RIGHT_OPEN:
      max_idx = (A[max_idx] > A[e]) ? max_idx : e;
      return TrapInterval(A, s, max_idx, CLOSED) +
             TrapInterval(A, max_idx, e, RIGHT_OPEN);

    default:
      return 0 / 0;
  }
}

int Trap(int A[], int n) {
  return TrapInterval(A, 0, n - 1, OPEN);
}
