#include "leetcode.h"

void NextPermutation(vector<int> &num) {
  int sz = num.size();
  int b = 0, e = sz - 1;
  for (int i = sz - 2; i >= 0; --i) {
    int min = -1, idx = -1;
    for (int j = i + 1; j < sz; ++j) {
      int diff = num[j] - num[i];
      if (diff > 0) {
        // if (min < 0 || diff <= min) {
        // NOTICE:
        // 1) There might be duplicate numbers
        // 2) We know [j, sz - 1] in descending order, we could have
        //    count backwards, starting from (sz - 1)
        if (min < 0 || diff <= min) {
          min = diff;
          idx = j;
        }
      }
    }

    if (min > 0) {
      int tmp = num[i];
      num[i] = num[idx];
      num[idx] = tmp;
      b = i + 1;
      break;
    }
  }

  while (b < e) { // by now, [b, e] in descending order...
    int tmp = num[b];
    num[b] = num[e];
    num[e] = tmp;
    ++b; --e;
  }
}

void NextPermutationNOTICE(vector<int> &num) {
  int sz = num.size();
  int b = 0, e = sz - 1;
  for (int i = sz - 2; i >= 0; --i) {
    bool swapped = false;

    for (int j = sz - 1; j > i; --j) {
      if (num[j] > num[i]) {
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
        b = i + 1;
        swapped = true;
        break;
      }
    }

    if (swapped) {
      break;
    }
  }

  while (b < e) { // by now, [b, e] in descending order...
    int tmp = num[b];
    num[b] = num[e];
    num[e] = tmp;
    ++b; --e;
  }
}
