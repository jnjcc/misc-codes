#include "leetcode.h"

ListNode *RotateRight(ListNode *head, int k) {
  if (head == NULL || k == 0) {
    return head;
  }
  int n = 1;
  ListNode *quick = head;
  while (quick->next) {
    quick = quick->next;
    ++n;
  }
  k = (n - k % n) % n;
  quick->next = head;
  while (k) {
    quick = quick->next;
    --k;
  }
  head = quick->next;
  quick->next = NULL;
  return head;
}
