/*
* this problem is not difficult
* Fist, I just get the max in the first window, then loop through all the windows and update max
* You just need to see how I deal with the three cases when updating max(line 30, 36, 38)
*/


int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if(k == 0) return NULL;
    
    int up_limit = numsSize - k + 1;
    *returnSize = up_limit;
    int *re = malloc(sizeof(int) * up_limit);
    
    int pre_max = INT_MIN;
    int pre_pos = -1;
    for(int i = 0; i < k; i++) {
        if(nums[i] > pre_max) {
            pre_max = nums[i];
            pre_pos = i;
        }
    }
    re[0] = pre_max;
    
    
    for(int i = 1; i < up_limit; i++) {
        if(pre_pos < i) {
            pre_max = INT_MIN;
            for(int j = i; j < i+k; j++) {
                if(nums[j] > pre_max) {
                    pre_max = nums[j];
                    pre_pos = j;
                }
            }
        } else {
            if(pre_max == nums[i + k - 1]) {
                pre_pos= i + k - 1;
            } else if(pre_max < nums[i + k -1]) {
                pre_pos = i + k -1;
                pre_max = nums[i+k-1];
            }
        }
        re[i] = pre_max;
    }
    return re;
}
