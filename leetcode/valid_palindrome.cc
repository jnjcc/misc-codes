#include "leetcode.h"

bool IsPalindromeString(const string &s) {
  int b = 0, e = s.size() - 1;
  while (b < e) {
    while (b < e && !isalnum(s[b])) {
      ++b;
    }
    while (b < e && !isalnum(s[e])) {
      --e;
    }
    if (b < e) {
      if (tolower(s[b]) == tolower(s[e])) {
        ++b; --e;
      } else {
        return false;
      }
    }
  }
  return true;
}
