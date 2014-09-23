#include "leetcode.h"

void PushTriple(vector<vector<int> > *pret, int a, int b, int c) {
  vector<int> triple;
  triple.push_back(a);
  triple.push_back(b);
  triple.push_back(c);
  pret->push_back(triple);
}

vector<vector<int> > ThreeSum(vector<int> &num) {
  vector<vector<int> > ret;
  if (num.size() < 3) {
    return ret;
  }

  sort(num.begin(), num.end());

  vector<int>::const_iterator pa, pb, pc;
  int sum = -1;
  for (pa = num.begin(); pa != num.end() - 2; ++pa) {
    if (pa > num.begin() && *pa == *(pa - 1)) {
      continue;
    }
    pb = pa + 1;
    pc = num.end() - 1;
    if (*pa > 0 || *pc < 0) {
      break;
    }

    while (pb < pc) {
      if (pb > pa + 1 && *pb == *(pb - 1)) {
        ++pb;
        continue;
      }
      if (pc < num.end() - 1 && *pc == *(pc + 1)) {
        --pc;
        continue;
      }
      sum = *pa + *pb + *pc;
      if (sum == 0) {
        PushTriple(&ret, *pa, *pb, *pc);
        ++pb;
        --pc;
      } else if (sum < 0) {
        ++pb;
      } else {
        --pc;
      }
    }
  }
  return ret;
}
