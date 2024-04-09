#include <cmath>
#include "exercises.h"

int maxCrossingSum(const int arr[], int l, int m, int h, int &i, int &j) {
    int sum = 0;
    int left_sum = INT_MIN;
    int max_left = m;
    for (int k = m; k >= l; k--) {
        sum = sum + arr[k];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = k;
        }
    }
    sum = 0;
    int right_sum = INT_MIN;
    int max_right = m;
    for (int k = m + 1; k <= h; k++) {
        sum = sum + arr[k];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = k;
        }
    }
    i = max_left;
    j = max_right;
    return left_sum + right_sum;
}

int maxSubArraySum(const int arr[], int l, int h, int &i, int &j) {
    if (l == h) {
        i = l;
        j = h;
        return arr[l];
    }
    int m = (l + h) / 2;
    int i1, j1, i2, j2, i3, j3;
    int left_sum = maxSubArraySum(arr, l, m, i1, j1);
    int right_sum = maxSubArraySum(arr, m + 1, h, i2, j2);
    int cross_sum = maxCrossingSum(arr, l, m, h, i3, j3);
    if (left_sum >= right_sum && left_sum >= cross_sum) {
        i = i1;
        j = j1;
        return left_sum;
    } else if (right_sum >= left_sum && right_sum >= cross_sum) {
        i = i2;
        j = j2;
        return right_sum;
    } else {
        i = i3;
        j = j3;
        return cross_sum;
    }
}

int maxSubsequenceDC(const int A[], unsigned int n, int &i, int &j) {
    return maxSubArraySum(A, 0, (int) n - 1, i, j);
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex1, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    int i, j;
    EXPECT_EQ(maxSubsequenceDC(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    EXPECT_EQ(maxSubsequenceDC(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    EXPECT_EQ(maxSubsequenceDC(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    EXPECT_EQ(maxSubsequenceDC(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}
