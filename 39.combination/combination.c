


int cmpfunc (const int * a, const int * b) {
   if(*a > *b)
       return 1;
    return 0;
}


int **re;
int **re_col;
int re_size;

void recur(int *list, int listSize, int *candidates, int candidatesSize, int target) {
    if(target < 0) return;
    if(target == 0) {
        qsort(list, listSize, sizeof(int), cmpfunc);
        for(int i = 0; i < re_size; i++) {
            if(re_col[0][i] == listSize) {
                bool flag = true;
                for(int j = 0; j < listSize; j++) {
                    if(re[i][j] != list[j]) {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    return;
            }
        }
        
        re[re_size] = malloc(sizeof(int) * listSize);
        for(int i = 0; i < listSize; i++) {
            re[re_size][i] = list[i];
        }
        re_col[0][re_size] = listSize;
        re_size++;
        return;
    }
    
    for(int i = 0; i < candidatesSize; i++) {
        if(candidates[i] <= target) {
            int *temp = malloc(sizeof(int) * listSize + 1);
            for(int j = 0; j < listSize; j++) {
                temp[j] = list[j];
            }
            temp[listSize] = candidates[i];
            recur(temp, listSize + 1, candidates, candidatesSize, target - candidates[i]);
        }
    }
}


int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    if(candidatesSize == 0) return NULL;
    re = malloc(sizeof(int) * 3000);
    re_size = 0;
    columnSizes[0] = malloc(sizeof(int) * 3000);
    for(int i = 0; i < 3000; i++)
        columnSizes[0][i] = 0;
    re_col = columnSizes;
    int *arr;
    int arr_size = 0;
    recur(arr, arr_size, candidates, candidatesSize, target);
    
    *returnSize = re_size;
    return re;
}
