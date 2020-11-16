/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int minLength = INT_MAX;
        int windowSum = 0;
        int windowStart = 0;

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++)
        {
            windowSum += nums[windowEnd];
            while (windowSum >= s)
            {
                minLength = min(minLength, windowEnd - windowStart + 1);
                windowSum -= nums[windowStart];
                windowStart++;
            }
        }

        return (minLength != INT_MAX) ? minLength : 0;
    }
};