#include "leetcode.h"

vector<int> PlusOne(vector<int> &digits) {
  vector<int> ret;
  int sz = digits.size();
  if (sz == 0) {
    return ret;
  }
  int carray = 1;
  int num = 0;
  for (int i = sz - 1; i >= 0; --i) {
    num = digits[i] + carray;
    carray = num / 10;
    ret.push_back(num % 10);
  }
  if (carray > 0) {
    ret.push_back(carray);
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
