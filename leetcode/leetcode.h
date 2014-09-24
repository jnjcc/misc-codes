#ifndef LEETCODE_H_
#define LEETCODE_H_

#include <stdio.h>
#include <math.h>

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
string LongestPalindrome(const string &text);

string ZigZagConvert(const string &s, int rows);

int Reverse(int x);

int Atoi(const char *str);

bool IsPalindrome(int x);

bool IsMatch(const char *s, const char *p);

int MaxArea(const vector<int> &height);

string IntToRoman(int num);
int RomanToInt(const string &s);

vector<vector<int> > ThreeSum(vector<int> &num);

int ThreeSumClosest(vector<int> &sum, int target);

vector<vector<int> > FourSum(vector<int> &sum, int target);

#endif  // LEETCODE_H_
