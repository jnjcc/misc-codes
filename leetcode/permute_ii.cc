#include "leetcode.h"

static void PermuteUniqDFS(const vector<int> &num, vector<bool> &used,
    vector<int> &perm, vector<vector<int> > &ret) {
  if (perm.size() == num.size()) {
    ret.push_back(perm);
    return;
  }

  for (int i = 0; i < num.size(); ++i) {
    if (i > 0 && num[i] == num[i - 1] && !used[i - 1]) {
      continue;
    }
    if (used[i]) {
      continue;
    }
    used[i] = true;
    perm.push_back(num[i]);
    PermuteUniqDFS(num, used, perm, ret);
    perm.pop_back();
    used[i] = false;
  }
}

vector<vector<int> > PermuteUnique(vector<int> &num) {
  sort(num.begin(), num.end());
  vector<vector<int> > ret;
  if (num.size() == 0) {
    return ret;
  }
  vector<int> perm;
  vector<bool> used(num.size(), false);

  PermuteUniqDFS(num, used, perm, ret);

  return ret;
}
