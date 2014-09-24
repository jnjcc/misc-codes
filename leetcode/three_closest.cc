#include "leetcode.h"

int ThreeSumClosest(vector<int> &num, int target) {
  int ret = 0;
  if (num.size() < 3) {
    return ret;
  }

  sort(num.begin(), num.end());

  int min_diff = -1;
  vector<int>::const_iterator pa, pb, pc;
  for (pa = num.begin(); pa != num.end() - 2; ++pa) {
    pb = pa + 1;
    pc = num.end() - 1;
    while (pb < pc) {
      int cur_sum = *pa + *pb + *pc;
      int cur_diff = abs(cur_sum - target);
      if (min_diff == -1 || cur_diff < min_diff) {
        ret = cur_sum;
        min_diff = cur_diff;
        if (ret == target) {
          return ret;
        }
      }
      if (cur_sum < target) {
        ++pb;
      } else {
        --pc;
      }
    }
  }
  return ret;
}
