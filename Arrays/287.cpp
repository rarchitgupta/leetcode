/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one duplicate number in nums, return this duplicate number.

Follow-ups:

How can we prove that at least one duplicate number must exist in nums? 
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slowPointer = nums[0];
        int fastPointer = nums[0];

        do
        {
            slowPointer = nums[slowPointer];
            fastPointer = nums[nums[fastPointer]];
        } while (slowPointer != fastPointer);

        slowPointer = nums[0];

        while (slowPointer != fastPointer)
        {
            slowPointer = nums[slowPointer];
            fastPointer = nums[fastPointer];
        }

        return fastPointer;
    }
};

/*
Initial approach = Sort Array and compare indexes one by one: O(nlogn) time and O(1) space
Better approach = Hashing: O(n) time and O(n) space
Best approach = Floyd Cycle Algorithm: O(n) time and O(1) space
*/