#ifndef LEETCODE_H_
#define LEETCODE_H_

#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> TwoSum(const vector<int> &numbers, int target);
vector<int> TwoSumMap(const vector<int> &numbers, int target);

double FindMedianSortedArrays(int A[], int m, int B[], int n);

int LengthOfLongestSubstring(string s);

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};
ListNode *AddTwoNumbers(ListNode *lhs, ListNode *rhs);

string LongestPalindromeNaive(const string &text);

#endif  // LEETCODE_H_
