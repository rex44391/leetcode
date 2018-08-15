
int counter;
int target;

void recur(int *nums, int index, int sum) {
    if(index == 0) {
        if(sum + nums[0] == target) counter++;
        if(sum - nums[0] == target) counter++;
        return;
    }
    recur(nums, index - 1, sum + nums[index]);
    recur(nums, index - 1, sum - nums[index]);
}


int findTargetSumWays(int* nums, int numsSize, int S) {
    counter = 0;
    target = S;
    recur(nums, numsSize - 1, 0);
    return counter;
}
