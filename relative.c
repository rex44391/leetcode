/*100% in speed and space. this is a variation of counting sort*/

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int *table = malloc(sizeof(int) * 1001);
    for(int i = 0; i < 1001; i++) {
        table[i] = 0;
    }
    
    for(int i = 0; i < arr1Size; i++) {
        table[arr1[i]] += 1;
    }
    
    int *re = malloc(sizeof(int) * arr1Size);
    int re_ptr = 0;
    for(int i = 0; i < arr2Size; i++) {
        for(int j = 0; j < table[arr2[i]]; j++) {
            re[re_ptr] = arr2[i];
            re_ptr += 1;
        }
        table[arr2[i]] = 0;
    }
    
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < table[i]; j++) {
            re[re_ptr] = i;
            re_ptr += 1;
        }
        table[i] = 0;
    }
    
    *returnSize = re_ptr;
    return re;
}


