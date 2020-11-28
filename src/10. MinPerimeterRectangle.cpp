#include "gtest/gtest.h"

/*
정수 N이 주어졌을 때 최소 둘레(perimeter)를 찾는 문제. 여기서 N은 사각형의 넓이.

예)
N = 30 이라면 다음과 같은 조합이 있을 수 있음
(1, 30), with a perimeter of 62,
(2, 15), with a perimeter of 34,
(3, 10), with a perimeter of 26,
(5, 6), with a perimeter of 22.
여기서 최소 넓이는 22 이므로 22를 리턴하면 된다.

힌트 : 
* 한 변의 길이가 정해지면 다른 한변의 길이는 자동으로 결정 된다. (w, h = 넓이 / w)
* 모든 w 에 대해 perimeter를 구해보고 최소값을 찾아 리턴하면 된다.
* w 의 범위는 [1, sqrt(넓이)] 로 한정할 수 있다.
* w 가 sqrt(넓이)에 가까울 수록 perimeter는 작아지므로 sqrt(넓이)에서 부터 1의 방향으로 순회하면 좀 더 빨리 찾을 수 있다.
** 그렇다 하더라도 O(sqrt(N)) 는 동일

주의 : 
* 최소값(1), 최대값(1,000,000,000), 소수(982,451,653)와 같은 최악의 경우에 대해 테스트가 필요하다.
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

int perimeter(int w, int h)
{
    return 2 * (w + h);
}

int solution(int N) { // 1 ~ 1,000,000,000
    int sol = perimeter(1, N);
    int rootN = static_cast<int>(sqrt(N));
    for (int i = rootN; i >= 1; i--)
    {
        if (N % i == 0)
        {
            auto ret = perimeter(i, N / i);
            return ret;
        }
    }

    return sol;
}

TEST(MinPerimeterRectangle, SimpleTest) {
    EXPECT_EQ(22, solution(30));
    EXPECT_EQ(4, solution(1));
    EXPECT_EQ(24, solution(36));
    EXPECT_EQ(28, solution(48));
    EXPECT_EQ(204, solution(101));
    EXPECT_EQ(1238, solution(1234));
}

TEST(MinPerimeterRectangle, ExtremeTest) {
    EXPECT_EQ(27116, solution(45664320));
    EXPECT_EQ(30972904, solution(15486451));
    EXPECT_EQ(40000, solution(100000000));
    EXPECT_EQ(1964903308, solution(982451653));
    EXPECT_EQ(126500, solution(1000000000));
}
