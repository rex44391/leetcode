/*
* Using dynamic programming backward to solve it 
*/

int lengthOfLIS(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    if(numsSize == 1) return 1;
    int max_len = INT_MIN;
    int *table = malloc(sizeof(int) * numsSize);
    table[numsSize - 1] = 0;
    for(int i = numsSize - 2; i >= 0; i--) {
        int max_index = -1;
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] < nums[j]) {
                if(max_index == -1) {
                    max_index = j;
                } else {
                    if(table[max_index] < table[j]) {
                        max_index = j;
                    }
                }
            }
        }
        if(max_index == -1) {
            table[i] = 0;
        } else {
            if(table[max_index] == 0) {
                table[i] = 2;
            } else {
                table[i] = table[max_index] + 1;
            }
            if(table[i] > max_len) {
                max_len = table[i];
            }
        }
    }
    
    if(max_len < 1)
        max_len = 1;
    
    return max_len;
}
