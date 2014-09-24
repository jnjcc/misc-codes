#include "leetcode.h"

void PushQuad(vector<vector<int> > *pret, int a, int b, int c, int d) {
  vector<int> quad;
  quad.push_back(a);
  quad.push_back(b);
  quad.push_back(c);
  quad.push_back(d);
  pret->push_back(quad);
}

vector<vector<int> > FourSum(vector<int> &num, int target) {
  vector<vector<int> > ret;
  if (num.size() < 4) {
    return ret;
  }

  sort(num.begin(), num.end());

  for (int i = 0; i < num.size() - 3; ++i) {
    if (i > 0 && num[i] == num[i - 1]) {
      continue;
    }
    for (int j = i+1; j < num.size() - 2; ++j) {
      if (j != i+1 && num[j] == num[j-1]) {
        continue;
      }
      int remain = target - num[i] - num[j];
      int l = j + 1;
      int r = num.size() - 1;
      while (l < r) {
        if (l > j + 1 && num[l] == num[l-1]) {
          ++l;
          continue;
        }
        if (r < num.size() - 1 && num[r] == num[r+1]) {
          --r;
          continue;
        }
        int sum = num[l] + num[r];
        if (sum == remain) {
          PushQuad(&ret, num[i], num[j], num[l], num[r]);
          ++l;
          --r;
        } else if (sum < remain) {
          ++l;
        } else {
          --r;
        }
      }
    }
  }
  return ret;
}
