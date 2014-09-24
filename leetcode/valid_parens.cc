#include "leetcode.h"

bool IsValidParens(const string &s) {
  stack<char> parens;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      parens.push(s[i]);
    } else {
      if (parens.empty()) {
        return false;
      } else if (s[i] == ')' && parens.top() != '(') {
        return false;
      } else if (s[i] == ']' && parens.top() != '[') {
        return false;
      } else if (s[i] == '}' && parens.top() != '{') {
        return false;
      }
      parens.pop();
    }
  }
  if (parens.empty()) {
    return true;
  }
  return false;
}
