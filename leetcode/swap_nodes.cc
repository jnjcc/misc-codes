#include "leetcode.h"

ListNode *SwapPairs(ListNode *head) {
  // pp -> p -> q
  ListNode *p = head, *q;
  ListNode *ret, *pp = NULL;
  if (p == NULL || p->next == NULL) {
    return p;
  }
  q = p->next;
  ret = q;
  while (q) {
    p->next = q->next;
    q->next = p;
    if (pp) {
      pp->next = q;
    }
    pp = p;
    p = p->next;
    if (p) {
      q = p->next;
    } else {
      q = NULL;
    }
  }
  return ret;
}
