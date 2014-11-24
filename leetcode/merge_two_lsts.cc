#include "leetcode.h"

ListNode *MergeTwoLists(ListNode *l1, ListNode *l2) {
  ListNode *ret = NULL, *prev = NULL, *tmp = NULL;

  while (l1 && l2) {
    if (l1->val <= l2->val) {
      tmp = l1;
      l1 = l1->next;
    } else {
      tmp = l2;
      l2 = l2->next;
    }
    if (prev) {
      prev->next = tmp;
      prev = tmp;
    } else {
      ret = tmp;
      prev = tmp;
    }
  }

  tmp = l1 ? l1 : l2;
  if (prev) {
    prev->next = tmp;
  } else {
    ret = tmp;
  }

  return ret;
}
