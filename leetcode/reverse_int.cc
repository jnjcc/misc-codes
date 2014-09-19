#include "leetcode.h"

// NOTICE: reversed integer might overflow...
int Reverse(int x) {
  int sign = 1;
  if (x < 0) {
    x = -x;
    sign = -1;
  }

  int y = x;
  int shift = 1;
  while (y/10 != 0) {
    shift *= 10;
    y /= 10;
  }

  int ret = 0;
  while (x != 0) {
    int digit = x % 10;
    ret += digit * shift;
    shift /= 10;
    x /= 10;
  }

  return sign * ret;
}
