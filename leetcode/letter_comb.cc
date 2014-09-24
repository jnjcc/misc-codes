#include "leetcode.h"

void LetterDFS(vector<string> *pret, const string &digits, string &byfar,
    int pos, int length, map<char, string> &dmp) {
  if (pos == length) {
    pret->push_back(byfar);
  } else {
    char dig = digits[pos];
    for (int i = 0; i < dmp[dig].size(); ++i) {
      byfar.append(1, dmp[dig][i]);
      LetterDFS(pret, digits, byfar, pos + 1, length, dmp);
      byfar.resize(byfar.size() - 1);
    }
  }
}

vector<string> LetterCombinations(const string &digits) {
  map<char, string> dmp; // digit map
  dmp['2'] = "abc"; dmp['3'] = "def";
  dmp['4'] = "ghi"; dmp['5'] = "jkl";
  dmp['6'] = "mno"; dmp['7'] = "pqrs";
  dmp['8'] = "tuv"; dmp['9'] = "wxyz";
  vector<string> ret;
  string byfar;
  LetterDFS(&ret, digits, byfar, 0, digits.size(), dmp);
  return ret;
}
