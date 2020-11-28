#include "pch.h"

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <ctime>

using namespace std;

// Greatest will always be: (X*Z > Y*Z ? X*Z : Y*Z) where
//   There are at least 5 elements
//   X = 제일 작은 두 수의 곱 (음수일수도 있음. 게의치 않음)
//   Z = 제일 큰 수
//   Y = 두번째 큰 수와 세번째 큰 수의 곱 (음수일 수도 있음. 게의치 않음)
// 예외경우 (0이 섞여 있으면??)
//   3개면 무조건 A[P]*A[Q]*A[R]
//   4개면 [a b c d] a 또는 b 또는 d가 0이면 bcd, c가 0이면 abd
//   4 elements - [a b c d] - return greater of abd or bcd
int solution(vector<int>& A) {
    int N = A.size();

    // Sort the array using built in sort, this is O(N*log(N))
    std::sort(A.begin(), A.end());

    if (N == 3) {
        return (A[0] * A[1] * A[2]);
    }

    if (N == 4) {
        if (A[2] == 0) return A[0] * A[1] * A[3];
        int abd = A[0] * A[1] * A[3];
        int bcd = A[1] * A[2] * A[3];
        return ((abd > bcd) ? abd : bcd);
    }

    int X = A[0] * A[1];
    int Y = A[N - 3] * A[N - 2];
    int Z = A[N - 1];

    return (((X * Z) > (Y * Z)) ? (X * Z) : (Y * Z));
}

TEST(Dominator, SimpleTest) 
{
	EXPECT_EQ(60, solution(vector<int>{ -3, 1, 2, -2, 5, 6 }));
    EXPECT_EQ(125, solution(vector<int>{ -5, -5, 4, 5 }));
    EXPECT_EQ(6, solution(vector<int>{ -3, -2, 0, 1 }));
}

