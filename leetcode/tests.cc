#include "leetcode.h"
#include <gtest/gtest.h>

TEST(TwoSum, iteration) {
  int array[] = {2, 7, 11, 15};
  vector<int> input(array, array + sizeof(array) / sizeof(array[0]));
  vector<int> ouput = TwoSum(input, 9);
  EXPECT_EQ(ouput[0], 1);
  EXPECT_EQ(ouput[1], 2);
}

TEST(TwoSumMap, map) {
  int array[] = {2, 7, 11, 15};
  vector<int> input(array, array + sizeof(array) / sizeof(array[0]));
  vector<int> ouput = TwoSumMap(input, 9);
  EXPECT_EQ(ouput[0], 1);
  EXPECT_EQ(ouput[1], 2);
}

TEST(FindMedianSortedArrays, kth) {
  int A[] = {1, 8, 9, 20};
  int B[] = {2, 3, 4, 30, 60};
  EXPECT_EQ((int)FindMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B,
        sizeof(B) / sizeof(B[0])), 8);

  int A2[] = {1000};
  int B2[] = {1001};
  EXPECT_EQ(FindMedianSortedArrays(A2, 1, B2, 1), 1000.5);
}

TEST(LengthOfLongestSubstring, map) {
  string s1 = "abcabcbb", s2 = "bbbbb";
  EXPECT_EQ(LengthOfLongestSubstring(s1), 3);
  EXPECT_EQ(LengthOfLongestSubstring(s2), 1);
}

TEST(AddTwoNumbers, list) {
  ListNode *l1 = new ListNode(2), *l2 = new ListNode(4), *l3 = new ListNode(3);
  ListNode *r1 = new ListNode(5), *r2 = new ListNode(6), *r3 = new ListNode(4);
  l1->next = l2; l2->next = l3;
  r1->next = r2; r2->next = r3;
  ListNode *ret = AddTwoNumbers(l1, r1);
  EXPECT_EQ(ret->val, 7);
  EXPECT_EQ(ret->next->val, 0);
  EXPECT_EQ(ret->next->next->val, 8);
}

TEST(LongestPalindromeNaive, navie) {
  EXPECT_EQ(LongestPalindromeNaive("bb"), "bb");
  EXPECT_EQ(LongestPalindromeNaive("ccc"), "ccc");
}

TEST(LongestPalindrome, Manacher) {
  EXPECT_EQ(LongestPalindrome("bb"), "bb");
  EXPECT_EQ(LongestPalindrome("ccc"), "ccc");
  EXPECT_EQ(LongestPalindrome("babcbabcbaccba"), "abcbabcba");
}

TEST(ZigZagConvert, convert) {
  string ret = ZigZagConvert("PAYPALISHIRING", 3);
  string ret2 = ZigZagConvert("A", 1);
  EXPECT_EQ(ZigZagConvert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}

TEST(Reverse, int) {
  EXPECT_EQ(Reverse(123), 321);
  EXPECT_EQ(Reverse(-123), -321);
  EXPECT_EQ(Reverse(1100), 11);
}

TEST(Atoi, int) {
  EXPECT_EQ(Atoi("+123"), 123);
  EXPECT_EQ(Atoi("-023"), -23);
  EXPECT_EQ(Atoi("2147483648"), 2147483647);
}

TEST(IsPalindrome, int) {
  EXPECT_EQ(IsPalindrome(121), true);
  EXPECT_EQ(IsPalindrome(-121), false);
  EXPECT_EQ(IsPalindrome(12), false);
}

TEST(IsMatch, recursive) {
  EXPECT_EQ(IsMatch("aab", "c*a*b"), true);
  EXPECT_EQ(IsMatch("b", ""), false);
  EXPECT_EQ(IsMatch("b", ".*"), true);
}

TEST(IntToRoman, int) {
  EXPECT_EQ(IntToRoman(99), "XCIX");
}

TEST(RomanToInt, string) {
  EXPECT_EQ(RomanToInt("XCIX"), 99);
}

TEST(ThreeSum, vector) {
  int array[] = {-1, 0, 1, 2, -1, -4};
  vector<int> num(array, array + sizeof(array) / sizeof(array[0]));
  vector<vector<int> > ret = ThreeSum(num);
  // <-1, 0, 1> & <-1, -1, 2>
  EXPECT_EQ(ret.size(), 2);
}

TEST(ThreeSumClosest, vector) {
  int a1[] = {-1, 0, 1, 2, -1, -4};
  int a2[] = {-1, 2, 1, -4};
  vector<int> num1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
  vector<int> num2(a2, a2 + sizeof(a2) / sizeof(a2[0]));
  int ret1 = ThreeSumClosest(num1, 0);
  int ret2 = ThreeSumClosest(num2, 1);
  EXPECT_EQ(ret1, 0);
  EXPECT_EQ(ret2, 2);
}

TEST(FourSum, vector) {
  int array[] = {1, 0, -1, 0, -2, 2};
  vector<int> num(array, array + sizeof(array) / sizeof(array[0]));
  vector<vector<int> > ret = FourSum(num, 0);
  // (-1,  0, 0, 1)
  // (-2, -1, 1, 2)
  // (-2,  0, 0, 2)
  EXPECT_EQ(ret.size(), 3);
}

TEST(LetterCombinations, string) {
  string digits = "23";
  vector<string> ret = LetterCombinations(digits);
  EXPECT_EQ(ret.size(), 9);
}

TEST(RemoveNthFromEnd, list) {
  ListNode *l1 = new ListNode(1), *l2 = new ListNode(2), *l3 = new ListNode(3),
           *l4 = new ListNode(4), *l5 = new ListNode(5);
  l1->next = l2; l2->next = l3; l3->next = l4; l4->next = l5;
  ListNode *ret = RemoveNthFromEnd(l1, 2);
  EXPECT_EQ(ret->val, 1);
  EXPECT_EQ(ret->next->val, 2);
  EXPECT_EQ(ret->next->next->val, 3);
  EXPECT_EQ(ret->next->next->next->val, 5);
}

TEST(IsValidParens, string) {
  EXPECT_EQ(IsValidParens("()[]{}"), true);
  EXPECT_EQ(IsValidParens("([)]"), false);
}

TEST(GenerateParenthesis, int) {
  vector<string> ret = GenerateParenthesis(3);
  // "((()))", "(()())", "(())()", "()(())", "()()()"
  EXPECT_EQ(ret.size(), 5);
}

TEST(SwapPairs, list) {
  ListNode *l1 = new ListNode(1), *l2 = new ListNode(2), *l3 = new ListNode(3);
  l1->next = l2; l2->next = l3;
  ListNode *ret = SwapPairs(l1);
  EXPECT_EQ(ret->val, 2);
  EXPECT_EQ(ret->next->val, 1);
  EXPECT_EQ(ret->next->next->val, 3);
}

TEST(ReverseKGroup, list) {
  ListNode *l1 = new ListNode(1), *l2 = new ListNode(2), *l3 = new ListNode(3),
           *l4 = new ListNode(4), *l5 = new ListNode(5);
  l1->next = l2; l2->next = l3; l3->next = l4; l4->next = l5;
  ListNode *ret = ReverseKGroup(l1, 3);
  EXPECT_EQ(ret->val, 3);
  EXPECT_EQ(ret->next->val, 2);
  EXPECT_EQ(ret->next->next->val, 1);
  EXPECT_EQ(ret->next->next->next->val, 4);
  EXPECT_EQ(ret->next->next->next->next->val, 5);
}

TEST(RemoveDuplicates, array) {
  int a[] = {1, 1, 2};
  EXPECT_EQ(RemoveDuplicates(a, 3), 2);
}

TEST(StrStr, char) {
  char *p1 = StrStr("abcdef", "cde");
  char *p2 = StrStr("", "");
  EXPECT_EQ(*p1, 'c');
  EXPECT_EQ(strlen(p2), 0);
}

TEST(Divide, int) {
  EXPECT_EQ(Divide(2147483647, 2), 1073741823);
}

TEST(FindSubstring, str) {
  string s = "barfoothefoobarman";
  string la[] = {"foo", "bar"};
  vector<string> va(la, la+2);
  vector<int> ret = FindSubstring(s, va);
  // [0, 9]
  EXPECT_EQ(ret.size(), 2);
}

TEST(NextPermutation, vector) {
  int a[] = {2, 3, 1, 3, 3};
  vector<int> va(a, a + 5);
  vector<int> va2(a, a + 5);
  NextPermutation(va);
  NextPermutationNOTICE(va2);
  EXPECT_EQ(va[3], 1);
  EXPECT_EQ(va2[3], 1);
  EXPECT_EQ(va[4], 3);
  EXPECT_EQ(va2[4], 3);
}

TEST(LongestValidParentheses, str) {
  EXPECT_EQ(LongestValidParentheses(")()())"), 4);
  EXPECT_EQ(LongestValidParentheses("()(()"), 2);
}

TEST(SearchRotated, int) {
  int a[] = {4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(SearchRotated(a, 7, 6), 2);
}

TEST(SearchRange, int) {
  int a[] = {5, 7, 7, 8, 8, 10};
  int b[] = {2, 2};
  vector<int> ret;
  ret = SearchRange(a, 6, 8);
  EXPECT_EQ(ret[0], 3);
  EXPECT_EQ(ret[1], 4);

  ret = SearchRange(a, 6, 11);
  EXPECT_EQ(ret[0], -1);
  EXPECT_EQ(ret[1], -1);

  ret = SearchRange(b, 2, 2);
  EXPECT_EQ(ret[0], 0);
  EXPECT_EQ(ret[1], 1);
}

TEST(SearchInsert, int) {
  int a[] = {1, 3, 5, 6};
  EXPECT_EQ(SearchInsert(a, 4, 5), 2);
  EXPECT_EQ(SearchInsert(a, 4, 2), 1);
  EXPECT_EQ(SearchInsert(a, 4, 7), 4);
  EXPECT_EQ(SearchInsert(a, 4, 0), 0);
}

TEST(CountAndSay, int) {
  EXPECT_EQ(CountAndSay(5), "111221");
}

TEST(CombinationSum, int) {
  int a[] = {2, 3, 6, 7};
  vector<int> cands(a, a + sizeof(a) / sizeof(a[0]));
  vector<vector<int> > ret = CombinationSum(cands, 7);
  EXPECT_EQ(ret.size(), 2);
  EXPECT_EQ(ret[0][2], 3);
  EXPECT_EQ(ret[1][0], 7);
}

TEST(CombinationSum2, int) {
  int a[] = {10, 1, 2, 7, 6, 1, 5};
  vector<int> cands(a, a + sizeof(a) / sizeof(a[0]));
  vector<vector<int> > ret = CombinationSum2(cands, 8);
  EXPECT_EQ(ret.size(), 4);
}

TEST(FirstMissingPositive, array) {
  int A[] = {3, 4, -1, 1};
  EXPECT_EQ(FirstMissingPositive(A, 4), 2);
}

TEST(Trap, array) {
  int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  EXPECT_EQ(Trap(A, sizeof(A) / sizeof(A[0])), 6);
}

TEST(Multiply, string) {
  string lhs = "234", rhs = "678";
  EXPECT_EQ(Multiply(lhs, rhs), "158652");
}

TEST(WildcardMatch, char) {
  EXPECT_EQ(WildcardMatch("aa", "a"), false);
  EXPECT_EQ(WildcardMatch("aa", "aa"), true);
  EXPECT_EQ(WildcardMatch("aaa", "aa"), false);
  EXPECT_EQ(WildcardMatch("aa", "*"), true);
  EXPECT_EQ(WildcardMatch("aa", "a*"), true);
  EXPECT_EQ(WildcardMatch("aa", "?*"), true);
  // NOTICE: how about this one
  EXPECT_EQ(WildcardMatch("aab", "c*a*b"), false);
}

TEST(LengthOfLastWord, char) {
  EXPECT_EQ(LengthOfLastWord("Hello World"), 5);
}

TEST(Pow, double) {
  // for NOTICE 2)
  EXPECT_EQ(Pow(0.00001, 2147483647), 0.0);
}
