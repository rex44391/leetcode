

int cmpfunc (const int * a, const int * b) {
   if(*a > *b)
       return 1;
    return 0;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    if(k == 0 && !nums) return NULL;
    int *re = malloc(sizeof(int) * k);
    int *counter = malloc(sizeof(int) * k);
    *returnSize = k;
    for(int i = 0; i < k; i++)
        counter[i] = -1;
    
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    
    int prev = nums[0];
    int count = 1;
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == prev)
            count++;
        else {
            if(count > counter[k - 1]) {
                int ptr = k - 1;
                while(ptr > -1 && count > counter[ptr]) {
                    if(ptr > 0) {
                        counter[ptr] = counter[ptr - 1];
                        re[ptr] = re[ptr - 1];
                    }
                    ptr--;
                }
                counter[ptr + 1] = count;
                re[ptr + 1] = prev;
            }
            
            count = 1;
            prev = nums[i];
        }
            
    }
    
    if(prev == nums[numsSize - 1]) {
        if(count > counter[k - 1]) {
            int ptr = k - 1;
            while(ptr > -1 && count > counter[ptr]) {
                if(ptr > 0) {
                    counter[ptr] = counter[ptr - 1];
                    re[ptr] = re[ptr - 1];
                }
                ptr--;
            }
            counter[ptr + 1] = count;
            re[ptr + 1] = prev;
        }
    }
    
    return re;
}
