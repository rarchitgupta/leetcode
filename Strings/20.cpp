/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            switch (c)
            {
            case '{':
                st.push('}');
                break;
            case '[':
                st.push(']');
                break;
            case '(':
                st.push(')');
                break;
            case '}':
            case ']':
            case ')':
                if (st.size() == 0 || c != st.top())
                    return false;
                else
                    st.pop();
            default:;
            }
        }

        return st.size() == 0;
    }
};