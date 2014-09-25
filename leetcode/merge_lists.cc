#include "leetcode.h"

struct ListNodeComparator {
  bool operator() (ListNode *lhs, ListNode *rhs) {
    return lhs->val > rhs->val;
  }
};
ListNode *MergeKLists(vector<ListNode *> &lists) {
  ListNode *ret = NULL, *p;
  priority_queue<ListNode *, vector<ListNode *>, ListNodeComparator> qu;
  for (int i = 0; i < lists.size(); ++i) {
    if (lists[i]) {
      qu.push(lists[i]);
    }
  }
  while (!qu.empty()) {
    ListNode *top = qu.top();
    if (ret == NULL) {
      ret = top;
      p = ret;
    } else {
      p->next = top;
      p = top;
    }
    qu.pop();
    if (top->next) {
      qu.push(top->next);
    }
  }
  return ret;
}
