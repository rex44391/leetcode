

int cmpfunc (int *a, int *b) {
    if(*a >= *b)
       return 1;
    return -1;
}



int removeDuplicates(int* nums, int numsSize) {
    int dup_counter = 0;
    int counter2 = 1;
    int prev = nums[0];
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == prev) {
            counter2++;
            if(counter2 > 2) {
                nums[i] = INT_MAX;
                dup_counter++;
            }
        } else {
            counter2 = 1;
            prev = nums[i];
        }
    }
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    return numsSize - dup_counter;
}
