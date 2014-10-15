#include "leetcode.h"

string Multiply(string num1, string num2) {
  if (num1.size() <= 0 || num2.size() <= 0 || num1 == "0" || num2 == "0") {
    return "0";
  }

  string ret;
  // length at most (m + n)
  ret.append(num1.size() + num2.size(), '0');
  reverse(num1.begin(), num1.end());
  reverse(num2.begin(), num2.end());

  for (int i = 0; i < num1.size(); ++i) {
    int sum = 0, carray = 0;
    int dig = num1[i] - '0';
    int j;
    for (j = 0; j < num2.size(); ++j) {
      sum = ret[i + j] - '0' + (num2[j] - '0') * dig + carray;
      ret[i + j] = sum % 10 + '0';
      carray = sum / 10;
    }
    while (carray != 0) {
      sum = ret[i + j] - '0' + carray;
      ret[i + j] = sum % 10 + '0';
      carray = sum / 10;
    }
  }

  int len = ret.size();
  while (len > 1 && ret[len - 1] == '0') {
    --len;
  }
  ret.resize(len);

  reverse(ret.begin(), ret.end());
  return ret;
}
