/*
In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &tree)
    {
        int maxCount = 0;
        int windowStart = 0;
        int windowEnd;
        unordered_map<int, int> fruitFrequency;

        for (windowEnd = 0; windowEnd < tree.size(); windowEnd++)
        {
            fruitFrequency[tree[windowEnd]]++;

            while ((int)fruitFrequency.size() > 2)
            {
                fruitFrequency[tree[windowStart]]--;
                if (fruitFrequency[tree[windowStart]] == 0)
                    fruitFrequency.erase(tree[windowStart]);

                windowStart++;
            }
            maxCount = max(maxCount, windowEnd - windowStart + 1);
        }
        return maxCount;
    }
};