#include "leetcode.h"

vector<Interval> InsertIntval(vector<Interval> &intervals, Interval newInterval) {
  vector<Interval> ret;

  bool no_new = false;
  for (int i = 0; i < intervals.size(); ++i) {
    const Interval &cur = intervals[i];
    if (no_new) {
      ret.push_back(cur);
    } else {
      if (cur.start > newInterval.start) {
        if (cur.start > newInterval.end) {
          ret.push_back(newInterval);
          ret.push_back(cur);
          no_new = true;
        } else {
          newInterval.end = max(newInterval.end, cur.end);
        }
      } else {
        if (cur.end < newInterval.start) {
          ret.push_back(cur);
        } else {
          newInterval.start = cur.start;
          newInterval.end = max(newInterval.end, cur.end);
        }
      }
    }
  }
  if (!no_new) {
    ret.push_back(newInterval);
  }
  return ret;
}
