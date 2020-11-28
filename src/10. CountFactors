#include "pch.h"

/*
# 인수 갯수 찾기

양수 N이 주어졌을 때 인수의 갯수를 찾는 문제

## 예

N = 24 라면 1, 2, 3, 4, 6, 8, 12, 24 인수가 있으므로 인수의 갯수 8을 리턴하면 된다.

## 힌트

* N = D * M, D가 정해지면 M은 자동으로 결정된다.
* 모든 정수 D에 대해 정수 M의 갯수를 찾으면 된다.
* D의 범위는 [1, sqrt(N)] 로 한정하면 된다. (D <= sqrt(N), M >= sqrt(N))
* 복잡도는 O(sqrt(N))

## 주의

* 인수 중에 sqrt(N)이 포함된 수(예: N = 4)에 대해서도 테스트가 필요
* 최소값(1), 최대값(2,147,483,647), 특이한 수(982,451,653)와 같은 최악의 경우에 대해 테스트가 필요하다.
*/
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <ctime>
#include <stack>

using namespace std;

int solution(int N) {
    int sol = 2;
    int root_n = (int)sqrt(N);
    bool exact = false;

    if (N == 1)
        return 1;

    if (N == root_n * root_n) // sqrt 딱떨어짐
        exact = true;

    for (int i = 2; i <= root_n; i++)
    {
        if (exact && (i) == root_n)
            ++sol;
        else if (N % i == 0)
            sol += 2;
    }

    return sol;
}

TEST(CountFactors, SimpleTest) 
{
    EXPECT_EQ(8, solution(24));
    EXPECT_EQ(3, solution(25));
    EXPECT_EQ(2, solution(2));
}

TEST(CountFactors, ExtremeTest) 
{
    EXPECT_EQ(1, solution(1));
    EXPECT_EQ(2, solution(2147483647));
    EXPECT_EQ(81, solution(100000000));
}

