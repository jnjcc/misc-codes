#include "leetcode.h"

vector<int> TwoSum(const vector<int> &numbers, int target) {
  vector<int> indices;
  int len = numbers.size();
  for (int i = 0; i < len; ++i) {
    for (int j = len - 1; j > i; --j) {
      if (numbers[j] == target - numbers[i]) {
        indices.push_back(i + 1);
        indices.push_back(j + 1);
        return indices;
      }
    }
  }
}

vector<int> TwoSumMap(const vector<int> &numbers, int target) {
  vector<int> indices;
  map<int, int> locs;
  map<int, int>::const_iterator cit;
  for (int i = 0; i < numbers.size(); ++i) {
    cit = locs.find(target - numbers[i]);
    if (cit != locs.end()) {
      indices.push_back(cit->second);
      indices.push_back(i + 1);
      return indices;
    } else {
      locs[numbers[i]] = i + 1;
    }
  }
}
