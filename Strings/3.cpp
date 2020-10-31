/*
Given a string s, find the length of the longest substring without repeating characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int arr[128] = {0};
        int i = 0, j = 0, count = 0;

        while (j < s.size())
        {
            if (!arr[s[j]])
            {
                arr[s[j++]]++;
                count = max(j - i, count);
            }
            else
                arr[s[i++]]--;
        }
        return count;
    }
};