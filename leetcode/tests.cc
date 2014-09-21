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
