#include "leetcode.h"

int Sqrtx(int x) {
  int low = 1, high = x / 2;
  if (x < 2) {
    return x;
  }
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (mid < x / mid) {
      low = mid + 1;
    } else if (mid > x / mid) {
      high = mid - 1;
    } else {
      return mid;
    }
  }
  return high;
}
