#include "leetcode.h"

void CombSumDFS(const vector<int> &cands, int s, int left, vector<int> &cur,
    vector<vector<int> > &ret) {
  if (left == 0) {
    ret.push_back(cur);
    return;
  }

  int e = cands.size();
  for (int i = s; i < e; ++i) {
    if (left < cands[i]) {
      break;
    }
    cur.push_back(cands[i]);
    CombSumDFS(cands, i, left - cands[i], cur, ret);
    cur.pop_back();
  }
}

vector<vector<int> > CombinationSum(vector<int> &candidates, int target) {
  vector<vector<int> > ret;
  vector<int> cur;
  if (candidates.size() == 0 || target <= 0) {
    return ret;
  }
  sort(candidates.begin(), candidates.end());
  CombSumDFS(candidates, 0, target, cur, ret);
  return ret;
}
