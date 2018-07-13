int cmpfunc (int * a, int * b) {
   if(*a>*b) return 1;
   else if(*a==*b) return 0;
   else return -1;
}

int singleNumber(int* nums, int numsSize) {
     
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int temp = nums[0];
    int counter = 1;
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == temp) {
            counter++;
        } else {
            if(counter != 3)
                return temp;
            temp = nums[i];
            counter = 1;
            
        }
    }
    return nums[numsSize-1];
}
