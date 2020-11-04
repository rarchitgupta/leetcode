/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSoFar = INT_MIN, maxEndingHere = 0;
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            maxEndingHere += nums[i];

            if (maxSoFar < maxEndingHere)
                maxSoFar = maxEndingHere;

            if (maxEndingHere < 0)
                maxEndingHere = 0;
        }
        return maxSoFar;
    }
};