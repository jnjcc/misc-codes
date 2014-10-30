#include "leetcode.h"

// NOTICE: I tried the recursive approach, but TLE...
bool CanJump(int A[], int n) {
  if (n <= 0) {
    return true;
  }
  int max_jump = A[0];
  int cur = 1;
  while (cur < n && max_jump >= cur) {  // can we reach CUR?
    if (A[cur] + cur > max_jump) {
      max_jump = A[cur] + cur;
    }
    ++cur;
  }
  return (max_jump >= n - 1);
}
