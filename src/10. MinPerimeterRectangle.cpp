#include "gtest/gtest.h"
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <ctime>
#include <stack>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.

int perimeter(int w, int h)
{
    return 2 * (w + h);
}

// cout << "this is a debug message" << endl;
int solution(int N) { // 1 ~ 1000000000
    // write your code in C++14 (g++ 6.2.0)
    int sol = perimeter(1, N);
    int rootN = static_cast<int>(sqrt(N));
    for (int i = rootN; i >= 1; i--)
    {
        if (N % i == 0)
        {
            auto ret = perimeter(i, N / i);
            //printf("w: %d, h: %d\t", i, N / i);
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

