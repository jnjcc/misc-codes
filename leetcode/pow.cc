#include "leetcode.h"

double Pow(double x, int n) {
  double ret = 1.0;
  if (n == 0) {
    return ret;
  }
  if (n < 0) {
    // NOTICE 1): if x is small, <1 / x^k> might turn out to be <1 / 0>
    x = 1 / x;
    n = -n;
  }
  // NOTICE 2): otherwise, POWER might become INT_MIN, which will be
  //   smaller than INT_MAX
  unsigned power = 1;
  double mul = x;
  while (n > 0) {
    power = 1;
    mul = x;
    while (power * 2 < (unsigned)n) {
      power *= 2;
      mul *= mul;
    }
    ret *= mul;
    n -= power;
  }
  return ret;
}
