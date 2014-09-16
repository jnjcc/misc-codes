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
