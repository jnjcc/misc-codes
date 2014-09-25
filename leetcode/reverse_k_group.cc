#include "leetcode.h"

ListNode *ReverseRecursive(ListNode *b, ListNode *e) {  // [b, e]
  if (b == e) {
    return e;
  } else {
    ListNode *r = ReverseRecursive(b->next, e);
    b->next = r->next;
    r->next = b;
    return b;
  }
}

ListNode *ReverseKGroup(ListNode *head, int k) {
  ListNode *ret = head, *prev = NULL;
  if (k <= 1) {
    return ret;
  }

  ListNode *pb = head, *pe = head;
  while (pe) {
    int i = 1;
    while (i < k && pe) {
      pe = pe->next;
      ++i;
    }
    if (i < k || pe == NULL) {
      // NOTICE: one-to-one correspondence between I and PE
      break;
    } else {
      if (prev) {
        prev->next = pe;
      } else {
        ret = pe;
      }
      prev = ReverseRecursive(pb, pe);
      pb = prev->next;
      pe = pb;
    }
  }
  return ret;
}
