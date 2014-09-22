#include "leetcode.h"

// NUM: [1, 3999]
string IntToRoman(int num) {
  string chars = "IVXLCDM";
  int denom = 1000;
  string ret = "";
  for (int i = 6; i >= 0; i -= 2) {
    int digit = num / denom;
    if (digit == 0) {
      denom /= 10;
      continue;
    }

    if (digit <= 3) {
      ret.append(digit, chars[i]);
    } else if (digit == 4) {
      ret.append(1, chars[i]);
      ret.append(1, chars[i + 1]);
    } else if (digit == 5) {
      ret.append(1, chars[i + 1]);
    } else if (digit <= 8) {
      ret.append(1, chars[i + 1]);
      ret.append(digit - 5, chars[i]);
    } else {
      ret.append(1, chars[i]);
      ret.append(1, chars[i + 2]);
    }
    num %= denom;
    denom /= 10;
  }
  return ret;
}
