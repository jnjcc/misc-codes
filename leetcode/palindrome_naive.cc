#include "leetcode.h"

// The naive approach
int ExpandPalindrome(const string &text, int *s, int *e) {
  int l = *s, r = *e;
  while (l >= 0 && r < text.size()) {
    if (text[l] == text[r]) {
      --l;
      ++r;
    } else {
      break;
    }
  }
  *s = l + 1;
  *e = r - 1;
  return *e - *s + 1;
}

string LongestPalindromeNaive(const string &text) {
  int max_len = -1, start = 0;

  int cur_max = -1;
  int s_cur = 0, e_cur = 0;
  for (int i = 0; i+1 < text.size(); ++i) {
    if (text[i] == text[i+1]) {
      s_cur = i - 1, e_cur = i + 2;
      cur_max = ExpandPalindrome(text, &s_cur, &e_cur);
      if (cur_max > max_len) {
        max_len = cur_max;
        start = s_cur;
      }
    }
    if (i+2 < text.size() && text[i] == text[i+2]) {
      s_cur = i - 1, e_cur = i + 3;
      cur_max = ExpandPalindrome(text, &s_cur, &e_cur);
      if (cur_max > max_len) {
        max_len = cur_max;
        start = s_cur;
      }
    }
  }
  return text.substr(start, max_len);
}

// http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
string PreProcess(const string &s) {
  int len = s.size();
  if (len == 0) {
    return "^$";
  }
  string ret = "^";
  for (int i = 0; i < len; ++i) {
    ret += ("#" + s.substr(i, 1));
  }
  ret += "#$";
  return ret;
}
string LongestPalindrome(const string &s) {
  string text = PreProcess(s);
  int n = text.size();
  int C = 0, R = 0;
  int *P = new int[n];
  for (int i = 1; i < n - 1; ++i) {
    int i_mirror = 2 * C - i;  // i' = C - (i - C)
    P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
    while (text[ i + P[i] + 1 ] == text[ i - P[i] - 1]) {
      ++P[i];
    }
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  int max_len = -1, center = -1;
  for (int i = 1; i < n-1; ++i) {
    if (P[i] > max_len) {
      max_len = P[i];
      center = i;
    }
  }
  delete [] P;
  return s.substr((center - max_len - 1) / 2, max_len);
}
