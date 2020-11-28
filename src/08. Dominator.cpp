#include "pch.h"

/*
# Dominator 찾기

Dominator : 배열 A에 절반 넘게 있는 값

이 문제는 vector A가 주어지면 A의 Dominator의 위치(어느 위치든)를 리턴하는 문제
Dominator 없으면 -1 리턴

## 예

A = [3, 4, 3, 2, 3, -1, 3, 3] 라면

0, 2, 4, 6 or 7 중에 아무거나 리턴 하면 된다. (return 값의 index에 해당하는 값이 dominator이면 됨)

## 힌트

* Dominator를 먼저 찾는다.
* Dominator와 같은 배열 요소를 찾아 인덱스를 리턴한다.
* 복잡도는 O(N)

## 주의

*/
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#include <stack>
#include <iterator>

using namespace std;

bool find_dominator(vector<int>& A, int& leader)
{
    int N = A.size();
    unordered_map<int, int> hist;

    // make histogram
    for (auto& el : A)
        hist[el]++;

    // find max count
    int max_count = 0;
    int dominator_candidate = 0;
    for (auto& bin : hist)
    {
        if (max_count < bin.second)
        {
            max_count = bin.second;
            dominator_candidate = bin.first;
        }
    }

    if (max_count * 2 <= N) // if it is not a dominator, return false
        return false;

    leader = dominator_candidate;
    return true;
}

int solution(vector<int>& A)
{   
    int dominator;
    if (!find_dominator(A, dominator))
        return -1;

    auto it = find(A.begin(), A.end(), dominator);

    return distance(A.begin(), it);
 }

TEST(Dominator, SimpleTest) 
{
    EXPECT_EQ(0, solution(vector<int>{3, 4, 3, 2, 3, -1, 3, 3}));
    EXPECT_EQ(0, solution(vector<int>{1}));
    EXPECT_EQ(-1, solution(vector<int>{1, 2}));
}

//TEST(Dominator, ExtremeTest)
//{        
//    //EXPECT_EQ(1, solution(1));
//    //EXPECT_EQ(2, solution(2147483647));
//    //EXPECT_EQ(81, solution(100000000));
//}

