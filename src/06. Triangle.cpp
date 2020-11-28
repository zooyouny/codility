#include "pch.h"

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <ctime>

using namespace std;

int solution(vector<int>& A) {
    int N = A.size();

    if (N < 3)
        return 0;

    sort(A.begin(), A.end());

    for (int i = 0; i < N - 2; i++)
    {
        long long int P = A[i];
        long long int Q = A[i + 1];
        long long int R = A[i + 2];

        if (P + Q > R && P + R > Q && Q + R > P)
            return 1;
    }
    return 0;
}

TEST(Dominator, SimpleTest) 
{
    EXPECT_EQ(1, solution(vector<int>{ 1, 2, 5, 8, 10, 20 }));
    EXPECT_EQ(0, solution(vector<int>{ 1, 5, 15, 10 }));
}
