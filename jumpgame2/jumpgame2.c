int jump(int* nums, int numsSize) {
    int *table = (int*)malloc(sizeof(int)*numsSize);
    table[numsSize - 1] = 0; 
    for(int i = numsSize - 2; i > -1; i--) {
        if(nums[i] == 0) {
            table[i] = 50000;
            continue;
        }
        if(i + nums[i] >= (numsSize-1) ) {
            table[i] = 1;
        } else {
            int min = 50000;
            int upper = numsSize - 1;
            if(upper > i+nums[i])
                upper = i+nums[i] + 1;
            
            for(int j = i + 1; j < upper; j++) {
                if( (1+table[j]) < min)
                    min = 1+table[j];
            }
            table[i] = min;
        }
    }
    return table[0];
}
