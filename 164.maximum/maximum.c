int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int maximumGap(int* nums, int numsSize) {
    if(numsSize < 2) return 0;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    int max_dist = INT_MIN;
    for(int i = 1; i < numsSize; i++) {
        int dist = nums[i] - nums[i-1];
        if(dist > max_dist)
            max_dist = dist;
    }
    return max_dist;
}
