#include "leetcode.h"

string LongestCommonPrefixNaive(const vector<string> &strs) {
  int nums = strs.size();
  string ret = "";
  if (nums == 0) {
    return ret;
  }
  for (int i = 0; i < strs[0].size(); ++i) {
    bool exists = true;
    for (int j = 1; j < nums; ++j) {
      if (strs[j].size() <= i || strs[j][i] != strs[0][i]) {
        exists = false;
        break;
      }
    }
    if (exists) {
      ret.append(1, strs[0][i]);
    } else {
      break;
    }
  }
  return ret;
}
