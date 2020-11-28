#include "pch.h"

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <ctime>

using namespace std;


int solution(string& S) {
    vector<char> ch_stack;

    for (int i = 0; i < (int)S.length(); i++)
    {
        if (S[i] == '{' || S[i] == '[' || S[i] == '(')
        {
            ch_stack.push_back(S[i]);
        }
        else if (S[i] == '}' || S[i] == ']' || S[i] == ')')
        {
            if (ch_stack.empty())
                return 0;
            if ((S[i] == '}' && ch_stack.back() == '{') ||
                (S[i] == ']' && ch_stack.back() == '[') ||
                (S[i] == ')' && ch_stack.back() == '('))
                ch_stack.pop_back();
            else
                return 0;
        }
    }
    return ch_stack.empty() ? 1 : 0;
}

TEST(Dominator, SimpleTest) 
{
    EXPECT_EQ(1, solution(string{ "{[()()]}" }));
    EXPECT_EQ(1, solution(string{ "" }));
    EXPECT_EQ(0, solution(string{ "([)()]" }));
}
