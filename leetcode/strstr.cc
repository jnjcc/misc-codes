#include "leetcode.h"

char *StrStr(const char *haystack, const char *needle) {
  if (!haystack || !needle) {
    return NULL;
  }
  char *h = (char *)haystack, *n;
  while (h) {
    n = (char *)needle;
    char *p = h;
    while (p && *p && n && *n) {
      if (*p != *n) {
        break;
      }
      ++p; ++n;
    }
    if (!*n) {
      return h;
    } else {
      if (!*p) {  // HAYSTACK used out...
        return NULL;
      } else {
        ++h;
      }
    }
  }
  return NULL;
}
