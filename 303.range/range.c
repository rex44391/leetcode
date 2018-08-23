//Using dynamic programming to solve this problem


typedef struct {
    int *table;
    int size;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *na = malloc(sizeof(NumArray));
    
    na->size = numsSize;
    na->table = malloc(sizeof(int) * numsSize);
    
    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
        na->table[i] = sum;
    }
    
    
    return na;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    if(!obj || i > j || i < 0 || j < 0 || i >= obj->size || j >= obj->size) return NULL;
    
    if(i == 0) {
        return obj->table[j];
    } else {
        return obj->table[j] - obj->table[i - 1];
    }
}

void numArrayFree(NumArray* obj) {
    if(!obj) return;
    free(obj->table);
    free(obj);
    return;
}
