/*
An integer N is given, representing the area of some rectangle.

The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).

The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.

For example, given integer N = 30, rectangles of area 30 are:

(1, 30), with a perimeter of 62,
(2, 15), with a perimeter of 34,
(3, 10), with a perimeter of 26,
(5, 6), with a perimeter of 22.
Write a function:

int solution(int N);

that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.

For example, given an integer N = 30, the function should return 22, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000,000].
*/
//

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
    int rootN = sqrt(N);
    for (int i = rootN; i >= 1; i--)
    {
        if (N % i == 0)
        {
            auto ret = perimeter(i, N / i);
            printf("w: %d, h: %d\t", i, N / i);
            return ret;
            //if (sol > ret)
            //    sol = ret;
        }
    }

    return sol;
}

int main()
{
    vector<int> a_v{
        30, // minimum 둘레는 22 : (5+6)*2
        1, // 최소값 둘레는 4 : (1+1)*2
        36, // simple 둘레는 24 : (6+6)*2
        48, // simple 둘레는 28 : (6+7)*2
        101, // simple 둘레는 204 : (101+1)*2
        1234, // small 둘레는 1238 : (618+2)*2
        45664320, // medium 둘레는 27116 : (6240+7318)*2
        15486451, // prime1 둘레는 30972904 : (1+15486451)*2
        100000000, // square 둘레는 40000 : (10000+10000)*2
        982451653, // prime2 둘레는 1964903308 : (1+982451653)*2
        1000000000 // extreme max 둘레는 126500 : (31250+32000)*2
    };

    //w: 5, h : 6      Answer : 22
    //w : 1, h : 1      Answer : 4
    //w : 6, h : 6      Answer : 24
    //w : 6, h : 8      Answer : 28
    //w : 1, h : 101    Answer : 204
    //w : 2, h : 617    Answer : 1238
    //w : 6240, h : 7318        Answer : 27116
    //w : 1, h : 15486451       Answer : 30972904
    //w : 10000, h : 10000      Answer : 40000
    //w : 1, h : 982451653      Answer : 1964903308
    //w : 31250, h : 32000      Answer : 126500

    for (auto& a : a_v)
    {
        auto sol = solution(a);
        cout << "Answer : " << sol << endl;
    }
}

