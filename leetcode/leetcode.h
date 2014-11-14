#ifndef LEETCODE_H_
#define LEETCODE_H_

#include <stdio.h>
#include <string.h>
#include <math.h>

#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>  // NOTICE
#include <queue>  // NOTICE
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

vector<string> LetterCombinations(const string &digits);

ListNode *RemoveNthFromEnd(ListNode *head, int n);

bool IsValidParens(const string &s);

vector<string> GenerateParenthesis(int n);

ListNode *SwapPairs(ListNode *head);

ListNode *ReverseKGroup(ListNode *head, int k);

int RemoveDuplicates(int A[], int n);

char *StrStr(const char *haystack, const char *needle);

int Divide(int dividend, int divisor);

vector<int> FindSubstring(const string &, const vector<string> &);

void NextPermutation(vector<int> &num);
void NextPermutationNOTICE(vector<int> &num);

int LongestValidParentheses(const string &s);

int SearchRotated(int A[], int n, int target);

vector<int> SearchRange(int A[], int n, int target);

int SearchInsert(int A[], int n, int target);

string CountAndSay(int n);

vector<vector<int> > CombinationSum(vector<int> &candidates, int target);

vector<vector<int> > CombinationSum2(vector<int> &num, int target);

int FirstMissingPositive(int A[], int n);

int Trap(int A[], int n);

string Multiply(string num1, string num2);

bool WildcardMatch(const char *s, const char *p);

int LengthOfLastWord(const char *s);

double Pow(double x, int n);

int MaxSubArray(int A[], int n);

vector<vector<int> > Permute(vector<int> &num);
vector<vector<int> > PermuteUnique(vector<int> &num);

vector<string> Anagrams(vector<string> &strs);

vector<int> SpiralOrder(vector<vector<int> > &matrix);
vector<vector<int> > GenerateMatrix(int n);

bool CanJump(int A[], int n);
int MinJumps(int A[], int n);

vector<vector<string> > SolveNQueens(int n);
int TotalNQueens(int n);

void Rotate(vector<vector<int> > &matrix);

struct Interval {
  int start;
  int end;
  Interval(): start(0), end(0) {}
  Interval(int s, int e): start(s), end(e) {}
};
vector<Interval> Merge(vector<Interval> &intervals);
vector<Interval> InsertIntval(vector<Interval> &intervals, Interval newInterval);

#endif  // LEETCODE_H_
