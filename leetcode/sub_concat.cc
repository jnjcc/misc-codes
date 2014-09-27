#include "leetcode.h"

vector<int> FindSubstring(const string &S, const vector<string> &L) {
  vector<int> ret;
  int ssize = S.size();
  int lsize = L.size();
  if (lsize == 0) {
    for (int i = 0; i < ssize; ++i) {
      ret.push_back(i);
    }
    return ret;
  }

  int wsize = L[0].size();
  int csize = lsize * wsize; // concatenation size
  if (ssize < csize) {
    return ret;
  }

  map<string, int> occurs;
  for (int i = 0; i < lsize; ++i) {
    ++occurs[L[i]];  // the first time it occurs, default constructed
  }

  map<string, int> cur;
  for (int i = 0; i + csize <= ssize; ++i) {
    cur.clear();
    bool matches = true;
    for (int j = 0; j < lsize; ++j) {
      string tmp = S.substr(i + j * wsize, wsize);
      if (occurs[tmp] > cur[tmp]) {
        ++cur[tmp];
      } else {
        matches = false;
        break;
      }
    }
    if (matches) {
      ret.push_back(i);
    }
  }
  return ret;
}
