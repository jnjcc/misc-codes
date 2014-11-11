#include "leetcode.h"

// NOTICE: when defined within class, we have to make this function _static_
//   otherwise, with an extra "this" pointer, SORT() will not accept it
static bool CompareInterval(const Interval &lhs, const Interval &rhs) {
  return lhs.start < rhs.start;
}

bool ValidInterval(const Interval &intv) {
  return intv.start <= intv.end;
}

vector<Interval> Merge(vector<Interval> &intervals) {
  sort(intervals.begin(), intervals.end(), CompareInterval);

  vector<Interval> ret;

  Interval byfar(0, -1);
  for (int i = 0; i < intervals.size(); ++i) {
    const Interval &intv = intervals[i];
    if (ValidInterval(byfar)) {
      if (byfar.end >= intv.start) {
        if (byfar.end < intv.end) {
          byfar.end = intv.end;
        }
      } else {
        ret.push_back(byfar);
        byfar.start = intv.start;
        byfar.end = intv.end;
      }
    } else {
      byfar.start = intv.start;
      byfar.end = intv.end;
    }
  }
  if (ValidInterval(byfar)) {
    ret.push_back(byfar);
  }
  return ret;
}
