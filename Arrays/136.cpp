/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int i;
        for (i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        for (auto i : freq)
            if (i.second == 1)
                return i.first;

        return -1;
    }
};