#include "leetcode.h"

bool IsMatch(const char *s, const char *p) {
  if (!s || !p) {
    return false;
  }
  if (*p == '\0') {
    return (*s == '\0');
  }

  const char *f = (p + 1); // looking forward
  if (*f == '*') {
    while ((*p == '.' && *s != '\0') || (*s == *p)) {
      if (IsMatch(s, p + 2)) {
        return true;
      }
      ++s;
    }
    return IsMatch(s, p + 2);
  } else {
    if ((*p == '.' && *s != '\0') || (*s == *p)) {
      return IsMatch(s + 1, p + 1);
    }
    return false;
  }
}
