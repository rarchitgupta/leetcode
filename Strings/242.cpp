/*
Given two strings s and t , write a function to determine if t is an anagram of s.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        int i;
        int count[26] = {0};
        for (i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                return false;
        }

        return true;
    }
};