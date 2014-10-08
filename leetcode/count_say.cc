#include "leetcode.h"

static string NextSeq(const string &cur) {
  string ret = "";
  int n = cur.size();
  int i = 0;
  while (i < n) {
    int j = i;
    while (j + 1 < n && cur[j+1] == cur[i]) {
      ++j;
    }
    char tmp[3];
    snprintf(tmp, sizeof(tmp), "%d%c", (j - i + 1), cur[i]);
    ret += tmp;
    i = j + 1;
  }
  return ret;
}

string CountAndSay(int n) {
  string ret = "";
  if (n < 1) {
    return ret;
  }
  ret += "1";
  for (int i = 1; i < n; ++i) {
    ret = NextSeq(ret);
  }
  return ret;
}
