/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 != 0)
            return false;

        int subsetSum = sum / 2;
        int n = nums.size();

        bool dp[subsetSum + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for (int curr : nums)
        {
            for (int j = subsetSum; j >= curr; j--)
            {
                dp[j] = dp[j] || dp[j - curr];
            }
        }

        return dp[subsetSum];
    }
};