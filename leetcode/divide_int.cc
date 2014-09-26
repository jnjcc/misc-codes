#include "leetcode.h"

int Divide(int dividend, int divisor) {
  if (dividend == 0) {
    return 0;
  }

  // NOTICE: otherwise, -DIVIDEND or -DIVISOR might overflow
  // i.e., INT_MIN
  long long lhs = dividend, rhs = divisor;
  int sign = 1;
  if (lhs < 0) {
    lhs = -lhs;
    sign = -1;
  }
  if (rhs < 0) {
    rhs = -rhs;
    sign = (sign == 1) ? -1 : 1;
  }

  long long counts, sums;
  int ret = 0;
  while (lhs >= rhs) {
    counts = 1;
    sums = rhs;
    while (sums + sums <= lhs) {
      // otherwise, TLE
      sums += sums;
      counts += counts;
    }
    // by now, (SUMS + SUMS > LHS)
    ret += counts;
    lhs -= sums;
  }
  return (sign == -1) ? -ret : ret;
}
