/*
* dynamic programming, 100% speed and O(1) space
*/

int minCostClimbingStairs(int* cost, int costSize) {
    if(costSize == 0) return NULL;
    if(costSize == 1) return cost[0];

    
    int prev2 = cost[0];
    int prev1 = cost[1];
    int current;
    for(int i = 2; i < costSize; i++) {
        if(prev2 < prev1)
            current = prev2 + cost[i];
        else
            current = prev1 + cost[i];
        prev2 = prev1;
        prev1 = current;
    }
    if(prev2 < prev1)
        return prev2;
    else
        return prev1;
}
