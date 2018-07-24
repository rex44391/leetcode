int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    if(numsSize < 1) return NULL;
    int *re = malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    if(numsSize == 1) {
        re[0] = nums[0];
        re[1] = 1;
        return re;
    }
    
    int *count = malloc(sizeof(int) * (numsSize + 1) );
    for(int i = 0; i < (numsSize + 1); i++) {
        count[i] = 0;
    }
    
    int target_sum = 0;
    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        target_sum += (i + 1);
        sum += nums[i];
        count[nums[i]]++;
        if(count[nums[i]] > 1)
            re[0] = nums[i];
    }
    re[1] = target_sum - (sum - re[0]);
    return re;
}
