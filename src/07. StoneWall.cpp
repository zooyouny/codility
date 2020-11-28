#include "pch.h"

/*
# StoneWall 

Cover "Manhattan skyline" using the minimum number of rectangles.

레벨이 Painless 로 되어 있지만 경험이 없으면 꽤나 당황스러운 문제

지으려고 하는 돌벽의 높이 정보가 담긴 배열 A가 주어졌을 때 사용되는 육면체 벽돌의 갯수를 최소화 하는 문제다. 
벽돌 하나의 너비와 높이는 자유다. 갯수만 최소화하여 리턴하면 된다.

## 예

A = [8, 8, 5, 7, 9, 8, 7, 4, 8] 라면, 다음과 같은 돌벽의 형태가 되는데, 벽돌의 갯수를 최소화 하면 7개만 사용하여 지을 수 있다.
        =                      =      
    ==  ==  =    ==            = =    =
    == ==== =    ==       ====        =
    == ==== =    ==       ====        =
    ======= =    == =====             =
    ======= =    == =====             =
    =========    == =====          == 
    =========    == =====          == 
    =========    == =====          == 
    =========    == =====          == 
                 1  2     3    4 5 6  7
## 힌트

* case 0. 처음에는 무조건 새로운 벽돌이 필요
* case 1. 사용하던 벽돌 높이와 같으면 기존 벽돌의 너비만 늘려서 사용할 수 있다.
* case 2. 사용하던 벽돌 높이들보다 현재 필요한 높이가 낮으면, 반드시 새로운 벽돌을 쓸 수 밖에 없다.
* case 3. 사용하던 벽돌 높이보다 현재 필요한 높이가 높으면, 단차가 나는 부분만 벽돌을 추가하고 아래 부분은 이전 사용벽돌의 너비를 늘려 사용 할 수 있다.

* 스택을 이용하면 쉽게 풀 수 있다. (스택의 용도를 어떻게 할 것인가가 핵심!)
.* 스택에는 현재 사용 중인 벽돌의 높이 정보가 포함되도록 하고, case 2 처럼 기존 벽돌을 못 쓰는 경우가 되면 pop 하면 된다.
..* push 할 때마다 사용되는 벽돌의 수가 증가하는 것이므로 count up 하면 된다.
.* 위의 예에서 stack 의 변화 상태를 정리하면 다음과 같음
..* [] -> [8] -> [6] -> [6, 7] -> [6, 7, 9] -> [6, 7, 8] -> [4] -> [4, 8] -> []
..* 위 과정에서 총 7번 push 되었으므로 7을 리턴하면 됨

## 주의

*/
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <ctime>
#include <stack>

using namespace std;

int solution(vector<int>& H)
{
    int W = H.size();
    int nRet = 0;
    stack<int> b_st;

    for (int i = 0; i < (int)W; i++)
    {
        while (!b_st.empty() && H[i] < b_st.top()) // 스택에 있는 높이보다 현재 벽이 더 낮으면
        {
            b_st.pop();
        }

        if (b_st.empty() || H[i] > b_st.top()) // 스택이 비어 있거나 현재 필요한 높이가 스택에 있는 벽돌 높이보다 높으면 스택킹
        {
            b_st.push(H[i]);
            ++nRet;
        }
    }

    return nRet;
}

TEST(Dominator, SimpleTest) 
{
    EXPECT_EQ(7, solution(vector<int>{8, 8, 5, 7, 9, 8, 7, 4, 8}));
    //EXPECT_EQ(0, solution(vector<int>{1}));
    //EXPECT_EQ(-1, solution(vector<int>{1, 2}));
}

//TEST(Dominator, ExtremeTest)
//{        
//    //EXPECT_EQ(1, solution(1));
//    //EXPECT_EQ(2, solution(2147483647));
//    //EXPECT_EQ(81, solution(100000000));
//}

