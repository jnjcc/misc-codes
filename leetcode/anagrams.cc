#include "leetcode.h"

vector<string> Anagrams(vector<string> &strs) {
  vector<bool> mask(strs.size(), false);
  map<string, int> groups;
  map<string, int>::iterator it;
  for (int i = 0; i < strs.size(); ++i) {
    string tmp(strs[i]);
    sort(tmp.begin(), tmp.end());
    it = groups.find(tmp);
    if (it != groups.end()) {
      mask[it->second] = true;
      mask[i] = true;
    } else {
      groups[tmp] = i;
    }
  }

  vector<string> ret;
  for (int i = 0; i < strs.size(); ++i) {
    if (mask[i]) {
      ret.push_back(strs[i]);
    }
  }
  return ret;
}
