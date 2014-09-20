#include "leetcode.h"

bool IsPalindrome(int x) {
  if (x < 0) {
    return false;
  } else if (x < 10) {
    return true;
  }

  int digits = 0;
  int y = x;
  while (y != 0) {
    digits += 1;
    y /= 10;
  }

  int shift = pow(10, digits / 2 - 1);
  int reversed = 0;
  while (shift > 0) {
    reversed += (x % 10) * shift;
    x /= 10;
    shift /= 10;
  }
  if (digits % 2) {
    x /= 10;
  }
  return (x == reversed);
}
