#include "leetcode.h"

int LongestValidParentheses(const string &s) {
  int ret = 0;
  stack<char> chars;
  stack<int> pos;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') {
      chars.push(s[i]);
      pos.push(i);
    } else if (s[i] == ')') {
      if (!chars.empty() && chars.top() == '(') {
        chars.pop();
        pos.pop();
        // pos.top() is the last invalid position
        int cur_len = chars.empty() ? (i + 1) : (i - pos.top());
        ret = max(ret, cur_len);
      } else {
        chars.push(s[i]);
        pos.push(i);
      }
    }
  }
  return ret;
}
