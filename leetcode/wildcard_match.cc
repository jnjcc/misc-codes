#include "leetcode.h"

// NOTICE: '?' / '*' are all standalone meta-character
bool WildcardMatch(const char *s, const char *p) {
  if (!s || !p) {
    return false;
  }

  const char *star = NULL;
  const char *prev = NULL;
  while (s && *s) {
    if (*p == '?' || *s == *p) {
      ++s;
      ++p;
      continue;
    }
    if (*p == '*') {
      // NOTICE: we don't need the old star...
      star = p++;  // everything's right by this star
      prev = s;
      continue;
    }
    if (star) {
      p = star + 1;
      s = ++prev;
      continue;
    }
    return false;
  }
  while (*p == '*') {
    ++p;
  }
  return (*p == '\0');
}
