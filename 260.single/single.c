int cmpfunc (int * a, int * b) {
   if(*a>*b) return 1;
   else if(*a==*b) return 0;
   else return -1;
}
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    *returnSize = 2;
    int *re = (int*)malloc(sizeof(int) * 2);
    int ptr = 0;
    int counter = 1;
    int temp = nums[0];
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == temp)
            counter++;
        else {
            if(counter < 2) {
                re[ptr] = temp;
                ptr++;
                if(ptr == 2)
                    break;    
            }
            temp = nums[i];
            counter = 1;
        }
    }
    if(ptr == 1)
        re[ptr] = temp;
    
    return re;
}
