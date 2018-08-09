int show_counter;

void addOne(int *arr, int size) {
    int carry = 0;
    int ptr = size - 1;
    do{
        if(arr[ptr] == 1) {
            show_counter--;
            arr[ptr] = 0;
            carry = 1;
        } else {
            arr[ptr] = 1;
            carry = 0;
            show_counter++;
        }
        ptr--;
    } while(carry != 0 && ptr >= 0);
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    *returnSize = pow(2, numsSize);

    columnSizes[0] = malloc(sizeof(int) * (*returnSize) );
    int **re = malloc(sizeof(int*) * (*returnSize));
    
    if(numsSize == 0) {
        columnSizes[0][0] = 0;
        return re;
    }
    
    int *show = malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++) {
        show[i] = 0;
    }
    show_counter = 0;
    int ptr = 0;
    
    while(ptr < (*returnSize)) {
        re[ptr] = malloc(sizeof(int) * show_counter);
        columnSizes[0][ptr] = show_counter;
        int ptr2 = 0;
        for(int i = 0; i < (*returnSize); i++) {
            if(show[i] == 1 && ptr2 < show_counter) {
                re[ptr][ptr2] = nums[i];
                ptr2++;
            }
        }
        addOne(show, numsSize);
        ptr++;
    }
    return re;
}
