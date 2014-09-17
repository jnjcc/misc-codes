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
