/*
* using dynamic programming to solve this question,
* it's time complexity is O(2n) and sapce one is O(n)
* I don't know how to solve this without division in constant space.
* (Maybe using bit operators?)
*/

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *table = malloc(sizeof(int) * numsSize);
    
    table[numsSize - 1] = nums[numsSize - 1];
    int multi = nums[numsSize - 1];
    for(int i = numsSize - 2; i > 0; i--) {
        multi *= nums[i];
        table[i] = multi;
    }
    
    int *re = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    multi = 1;
    for(int i = 0; i < numsSize - 1; i++) {
        re[i] = multi * table[i + 1];
        multi *= nums[i];
    }
    re[numsSize - 1] = multi;
    return re;
}
