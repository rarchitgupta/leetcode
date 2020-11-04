/*
Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target)
                high = mid - 1;
            if (nums[mid] < target)
                low = mid + 1;
        }
        return -1;
    }
};