#include "leetcode.h"
#include <limits.h>

int Atoi(const char *str) {
  int sign = 1;
  // int ret = 0;
  long long ret = 0; // for overflow
  if (str == NULL) {
    return ret;
  }
  char *p = (char *)str;

  while (p && isspace(*p)) {
    ++p;
  }

  if (p && *p == '+') {
    sign = 1;
    ++p;
  } else if (p && *p == '-') {
    sign = -1;
    ++p;
  }
  while (p && *p) {
    if (ret == 0 && *p == '0') {
      ++p;
    } else if (*p >= '0' && *p <= '9') {
      ret = ret * 10 + (*p - '0');
      ++p;
    } else {
      break;
    }
  }

  ret *= sign;
  if (ret > INT_MAX) {
    ret = INT_MAX;
  } else if (ret < INT_MIN) {
    ret = INT_MIN;
  }
  return ret;
}
