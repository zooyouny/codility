#include "pch.h"

/*
# EquiLeader 찾기

Leader : 시퀀스에 절반 넘게 있는(occurs more than half of) 값
Equi Leader : 다음을 만족하는 인덱스 S
* 여기서 S는 0 ≤ S < N − 1
* A[0]~A[S], A[S+1]~A[N-1] 두 시퀀스는 같은 leader값을 갖음

이 문제는 vector A가 주어지면 equi leader의 갯수를 리턴하는 문제

## 예

A = [4, 3, 4, 4, 4, 2] 라면

* S=0, [4], [3, 4, 4, 4, 2] 두 시퀀스의 leader는 4
* S=3, [4, 3, 4], [4, 4, 2] 두 시퀀스의 leader는 4

## 힌트

* leader를 먼저 찾는다.
* S가 정해지면 두 시퀀스가 정해진다.
* 각 시퀀스의 leader를 찾고, 같은지 확인하고 같으면 count up 한다.
** 이렇게 하면 leader를 찾는 행위가 불필요하게 반복됨
** **leader count의 "부분합"을 이용하여 불필요한 반복을 제거!!**
* 모든 S에 대해 반복 수행한다.
** S 의 범위는 [0, N-2]
* 복잡도는 O(N)

## 주의

* A의 길이 N의 범위 [1..100,000], 각 요소의 값의 범위는 [−1,000,000,000..1,000,000,000] (대략 int)

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

// find leader, and return existance of the leader
// O(N)
bool find_leader(vector<int>& A, int& leader)
{
    int N = A.size();
    unordered_map<int, int> hist;

    // make histogram
    for (auto& el : A)
        hist[el]++;

    // find max count
    int max_count = 0;
    int leader_candidate = 0;
    for (auto& bin : hist)
    {
        if (max_count < bin.second)
        {
            max_count = bin.second;
            leader_candidate = bin.first;
        }
    }

    if (max_count * 2 <= N) // if it is not a leader, return false
        return false;

    leader = leader_candidate;
    return true;
}

int solution(vector<int>& A) {
    int N = A.size();
    int sol = 0;

    int leader;
    if (!find_leader(A, leader))
        return 0;

    // leader 부분 합
    vector<int> p_sum_leader(N, 0);
    int t_count = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == leader)
            ++t_count;
        p_sum_leader[i] = t_count;
    }

    // count equileader
    for (int S = 0; S < N - 1; S++) // S [0, N - 1)
    {
        int l_sq_size = S + 1;
        int r_sq_size = N - l_sq_size;
        const int l_sq_leader_count = p_sum_leader[S];
        const int r_sq_leader_count = p_sum_leader[N - 1] - p_sum_leader[S]; // given A = [1, 1, 2, 3, 4, 4], if S = 2, then p_sum[N - 1] = 4 and p_sum[S] = 2

        if (l_sq_leader_count * 2 > l_sq_size // if S = 2, then l_count = 2 * 2 and l_sq_size = 3
            && r_sq_leader_count * 2 > r_sq_size)// if S = 2, then r_count = 2 * 2 and l_sq_size = 3
            sol++;
    }

    return sol;
}

TEST(CountFactors, SimpleTest) 
{
    EXPECT_EQ(2, solution(vector<int>{4, 3, 4, 4, 4, 2}));
    EXPECT_EQ(0, solution(vector<int>{1})); // single element
    EXPECT_EQ(1, solution(vector<int>{1, 1})); // two elements
}

TEST(CountFactors, ExtremeTest) 
{        
    //EXPECT_EQ(1, solution(1));
    //EXPECT_EQ(2, solution(2147483647));
    //EXPECT_EQ(81, solution(100000000));
}

