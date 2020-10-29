/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> disappeared;
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            nums[index] = (nums[index] > 0) ? -nums[index] : nums[index];
        }

        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                disappeared.push_back(i + 1);
        }

        return disappeared;
    }
};