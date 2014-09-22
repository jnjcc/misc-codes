#include "leetcode.h"

int RomanToInt(const string &s) {
  map<char, int> char_maps;
  char_maps['I'] = 1; char_maps['V'] = 5;
  char_maps['X'] = 10; char_maps['L'] = 50;
  char_maps['C'] = 100; char_maps['D'] = 500;
  char_maps['M'] = 1000;

  int ret = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (i+1 < n && char_maps[s[i]] < char_maps[s[i+1]]) {
      ret -= char_maps[s[i]];
    } else {
      ret += char_maps[s[i]];
    }
  }
  return ret;
}
