/*
We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> subsetSum(vector<int> arr, int sum, int n)
    {
        int t[n + 1][sum + 1];
        int i, j;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < sum; j++)
            {
                if (i == 0)
                    t[i][j] = false;
                if (j == 0)
                    t[i][j] = true;
            }
        }

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        vector<int> res;
        for (j = 0; j <= sum / 2; j++)
        {
            if (t[n][j] == true)
            {
                res.push_back(j);
            }
        }

        return res;
    }

    int lastStoneWeightII(vector<int> &stones)
    {
        int sumTotal = 0;
        for (int i : stones)
            sumTotal += i;

        vector<int> res;
        int n = stones.size();
        res = subsetSum(stones, sumTotal, n);
        int minDifference = INT_MAX;

        for (int i = 0; i < res.size(); i++)
            minDifference = min(minDifference, (sumTotal - (2 * res[i])));

        return minDifference;
    }
};