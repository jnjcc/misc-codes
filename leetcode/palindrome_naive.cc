#include "leetcode.h"

string LongestPalindromeNaive(const string &text) {
  // Start index, End index, max PAlindrome length
  int s_max = 0, e_max = 0, pa_max = -1;

  int cur_max = -1;
  int s_cur = 0, e_cur = 0;
  for (int i = 0; i+1 < text.size(); ++i) {
    if (text[i] == text[i+1]) {
      s_cur = i - 1, e_cur = i + 2;
      while (s_cur >= 0 && e_cur < text.size()) {
        if (text[s_cur] == text[e_cur]) {
          --s_cur; ++e_cur;
        } else {
          break;
        }
      }
      cur_max = e_cur - s_cur - 1;
      if (cur_max > pa_max) {
        pa_max = cur_max;
        s_max = s_cur + 1;
        e_max = e_cur - 1;
      }
    }
    if (i+2 < text.size() && text[i] == text[i+2]) {
      s_cur = i - 1, e_cur = i + 3;
      while (s_cur >= 0 && e_cur < text.size()) {
        if (text[s_cur] == text[e_cur]) {
          --s_cur; ++e_cur;
        } else {
          break;
        }
      }
      cur_max = e_cur - s_cur - 1;
      if (cur_max > pa_max) {
        pa_max = cur_max;
        s_max = s_cur + 1;
        e_max = e_cur - 1;
      }
    }
  }
  return text.substr(s_max, pa_max);
}
