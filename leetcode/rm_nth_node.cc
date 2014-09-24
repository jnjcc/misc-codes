#include "leetcode.h"

// N will always be valid
ListNode *RemoveNthFromEnd(ListNode *head, int n) {
  ListNode *prev = head, *rm = head, *quick = head;
  ListNode *ret = head;

  int i = 0;
  while (i < n) {
    quick = quick->next;
    ++i;
  }
  while (quick != NULL) {
    quick = quick->next;
    prev = rm;
    rm = rm->next;
  }
  if (rm == head) {
    ret = head->next;
    delete head;
  } else {
    prev->next = rm->next;
    delete rm;
  }
  return ret;
}
