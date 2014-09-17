#include "leetcode.h"

int LengthOfLongestSubstring(string s) {
  map<char, int> locs;
  int max_len = 0, start = 0;  // [start, ]
  for (int i = 0; i < s.size(); ++i) {
    if (locs.find(s[i]) != locs.end() && start <= locs[s[i]]) {
      start = locs[s[i]] + 1;
    }
    locs[s[i]] = i;
    max_len = max(max_len, i - start + 1);  // [start, i]
  }
  return max_len;
}
