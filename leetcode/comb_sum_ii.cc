#include "leetcode.h"

void CombSumDFS2(const vector<int> &cands, int s, int left, vector<int> &cur,
    vector<vector<int> > &ret) {
  if (left == 0) {
    ret.push_back(cur);
    return;
  }

  int e = cands.size();
  for (int i = s; i < e; ++i) {
    if (i > s && cands[i] == cands[i - 1]) {
      continue;
    }
    if (left < cands[i]) {
      break;
    }
    cur.push_back(cands[i]);
    CombSumDFS2(cands, i + 1, left - cands[i], cur, ret);
    cur.pop_back();
  }
}

vector<vector<int> > CombinationSum2(vector<int> &num, int target) {
  vector<vector<int> > ret;
  vector<int> cur;
  if (num.size() == 0 || target <= 0) {
    return ret;
  }
  sort(num.begin(), num.end());
  CombSumDFS2(num, 0, target, cur, ret);
  return ret;
}
