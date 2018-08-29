int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    if(findNumsSize == 0 || numsSize == 0) return NULL;
    
    int *re = malloc(sizeof(int) * findNumsSize);
    *returnSize = findNumsSize;
    
    //memorize the position in nums
    for(int i = 0; i < findNumsSize; i++) {
        for(int j = 0; j < numsSize; j++) {
            if(findNums[i] == nums[j]) {
                re[i] = j;
                break;
            }
        }
    }
    
    //search the next greater elem in nums
    for(int i = 0; i < findNumsSize; i++) {
        int pos = re[i] + 1;
        re[i] = -1;
        for(int j = pos; j < numsSize; j++) {
            if(nums[j] > findNums[i]) {
                re[i] = nums[j];
                break;
            }
        }
    }
    return re;
}
