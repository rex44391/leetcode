bool canJump(int* nums, int numsSize) {
    bool *table = (bool*)malloc(sizeof(bool) * numsSize);
    table[numsSize - 1] = true;
    
    for(int i = numsSize - 2; i > -1; i--) {
        if(nums[i] == 0) {
            table[i] = false;
            continue;
        }
        if( (i + nums[i]) >= (numsSize -1) ) {
            table[i] = true;
        } else {
            table[i] = false;
            int upper = numsSize - 1;
            if(upper > (i + nums[i]) )
                upper = i + nums[i] + 1;
            
            for(int j = i + 1; j < upper; j++) {
                if(table[j]) {
                    table[i] = true;
                    break;
                }
            }
        }
    }
    
    return table[0];
}
