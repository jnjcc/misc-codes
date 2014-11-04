#include "leetcode.h"

int MinJumps(int A[], int n) {
  int ret = 0;
  if (n <= 1) {
    return ret;
  }

  // [BEG, END]: the positions we can get after k steps
  //   if we can get there after k steps, we will not allow (k+1)
  // MAX: how far we can get for the (k+1)-th step, starting from [BEG, END]
  int beg = 0, end = 0, max = 0;
  while (beg <= max) {
    ret++;
    end = max + 1;
    for (int i = beg; i < end; ++i) {
      // choose the max position we can get from this step
      if (A[i] + i > max) {
        max = A[i] + i;
        if (max >= n - 1) {
          return ret;
        }
      }
    }
    beg = end;
  }
  return ret;
}
