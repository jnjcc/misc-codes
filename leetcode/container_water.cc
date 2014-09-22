#include "leetcode.h"

int MaxArea(const vector<int> &height) {
  int n = height.size();
  int l = 0, r = n - 1;
  int max_area = -1;
  while (l < r) {
    int cur_area = min(height[l], height[r]) * (r - l);
    if (cur_area > max_area) {
      max_area = cur_area;
    }
    if (height[l] < height[r]) {
      ++l;
    } else {
      --r;
    }
  }
  return max_area;
}
