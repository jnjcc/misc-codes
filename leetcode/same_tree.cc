#include "leetcode.h"

bool IsSameTree(TreeNode *p, TreeNode *q) {
  if (!p && !q) {
    return true;
  }
  if (!p || !q || p->val != q->val) {
    return false;
  }
  return IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right);
}
