#include "leetcode.h"

ListNode *AddTwoNumbers(ListNode *lhs, ListNode *rhs) {
  ListNode *ret = NULL;

  ListNode *prev = NULL, *cur = NULL;
  int carray = 0;
  while (lhs && rhs) {
    int sum = (lhs->val + rhs->val + carray);
    carray = sum / 10;
    cur = new ListNode(sum % 10);
    if (!ret) {
      ret = cur;
    }
    if (prev) {
      prev->next = cur;
    }
    prev = cur;
    lhs = lhs->next;
    rhs = rhs->next;
  }

  ListNode *left = lhs ? lhs : rhs;
  while (left) {
    int sum = left->val + carray;
    carray = sum / 10;
    cur = new ListNode(sum % 10);
    if (!ret) {
      ret = cur;
    }
    if (prev) {
      prev->next = cur;
    }
    prev = cur;
    left = left->next;
  }

  if (carray != 0) {
    cur = new ListNode(carray);
    if (prev) {
      prev->next = cur;
    }
    prev = cur;
  }
  return ret;
}
