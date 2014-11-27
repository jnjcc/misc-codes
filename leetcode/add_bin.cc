#include "leetcode.h"

int KeepSum(int sum, string *pret) {
  int carray = 0;
  switch (sum) {
    case 0: case 2:
      pret->push_back('0');
      break;
    case 1: case 3:
      pret->push_back('1');
      break;
  }
  if (sum >= 2) {
    carray = 1;
  }
  return carray;
}

string AddBinary(string a, string b) {
  string ret;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int carray = 0;
  int i = 0, j = 0;
  int m = a.size(), n = b.size();
  while (i < m && j < n) {
    int sum = (a[i] - '0') + (b[j] - '0') + carray;
    carray = KeepSum(sum, &ret);
    ++i; ++j;
  }
  while (i < m) {
    int sum = (a[i] - '0') + carray;
    carray = KeepSum(sum, &ret);
    ++i;
  }
  while (j < n) {
    int sum = (b[j] - '0') + carray;
    carray = KeepSum(sum, &ret);
    ++j;
  }
  if (carray > 0) {
    ret.push_back('1');
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
