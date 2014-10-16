#include "leetcode.h"

int LengthOfLastWord(const char *s) {
  int ret = 0;
  if (!s) {
    return ret;
  }
  const char *p = s;
  while (p && *p) {
    if (*p != ' ') {
      ret = 0;
      while (*p && *p != ' ') {
        ++ret;
        ++p;
      }
    } else {
      ++p;
    }
  }
  return ret;
}
