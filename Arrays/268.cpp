/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int arraySum = 0;
        for (int i = 0; i < nums.size(); i++)
            arraySum += nums[i];

        int expectedSum = ((nums.size()) * (nums.size() + 1)) / 2;

        return (expectedSum - arraySum);
    }
};