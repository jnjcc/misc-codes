#include "leetcode.h"

void MinStack::Push(int x) {
  elems_.push(x);
  if (mins_.empty() || x <= mins_.top()) {
    mins_.push(x);
  }
}

void MinStack::Pop() {
  if (elems_.empty()) {
    return;
  }
  int x = elems_.top();
  if (x == mins_.top()) {
    mins_.pop();
  }
  elems_.pop();
}

int MinStack::Top() {
  return elems_.top();
}

int MinStack::GetMin() {
  return mins_.top();
}
