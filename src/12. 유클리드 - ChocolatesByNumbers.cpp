#include "pch.h"

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

/*
	10, 4 -> 0, 4, 8, 2, 6
	
	한 바퀴 돌았을 때 N만큼을 더해주면 다음과 같이 표현 가능
	10, 4 -> 0, 4, 8, 12, 16 -> 4*0, 4*1, 4*2, 4*3, 4*4 < lcm(N, M)

	즉, lcm(N, M)에서 M 값으로 나눈 값과 같음	

	주의 : 곱하기가 있을때는 범위 벗어 날 수 있으므로 타입 유의
*/

int gcd(int a, int b)
{
#if RECURSIVE
	gcd(b, a % b);
#else
	while (b>0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
#endif 
	return a;
}

int64_t lcm(int a, int b)
{
	return ((int64_t)a * b) / gcd(a, b);
}

int solution(int N, int M) {
	return lcm(N, M) / M;
}

TEST(Dominator, SimpleTest) 
{
	EXPECT_EQ(5, solution(10, 4));
	EXPECT_EQ(1, solution(1, 1));
	EXPECT_EQ(2, solution(2, 1));
	EXPECT_EQ(3, solution(3, 1));
	EXPECT_EQ(3, solution(3, 2));
	//	EXPECT_EQ(0, solution(1, 2));
}

TEST(Dominator, ExtremeTest)
{        
    EXPECT_EQ(947853, solution(947853, 4453));
    //EXPECT_EQ(2, solution(2147483647));
    //EXPECT_EQ(81, solution(100000000));
}

