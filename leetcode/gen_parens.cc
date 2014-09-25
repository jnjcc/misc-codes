#include "leetcode.h"

void ParensDFS(vector<string> *pret, string &byfar, int stack, int n) {
  if (n == 0) {  // used out
    byfar.append(stack, ')'); // number of '(' "on stack"
    pret->push_back(byfar);
    byfar.resize(byfar.size() - stack);
  } else {
    byfar.append(1, '(');
    ParensDFS(pret, byfar, stack + 1, n - 1);
    byfar.resize(byfar.size() - 1);

    if (stack > 0) {
      byfar.append(1, ')');
      ParensDFS(pret, byfar, stack - 1, n);
      byfar.resize(byfar.size() - 1);
    }
  }
}

vector<string> GenerateParenthesis(int n) {
  vector<string> ret;
  string byfar;
  ParensDFS(&ret, byfar, 0, n);
  return ret;
}
