int cmpfunc (const int * a, const int * b) {
   if(*a > *b)
       return 1;
    return 0;
}


int **re;
int **re_col;
int re_size;
int *candidates;
int candidatesSize;

void recur(int *list, int listSize, int cand_start, int k, int target) {

    if(target < 0 || k < 0) return;
    if(target == 0 && k == 0) {
        re[re_size] = malloc(sizeof(int) * listSize);
        for(int i = 0; i < listSize; i++) {
            re[re_size][i] = list[i];
        }
        re_col[0][re_size] = listSize;
        re_size++;
        return;
    }
    
    
    for(int i = cand_start; i < candidatesSize; i++) {
        if(candidates[i] <= target) {
            int *temp = malloc(sizeof(int) * listSize + 1);
            for(int j = 0; j < listSize; j++) {
                temp[j] = list[j];
            }
            temp[listSize] = candidates[i];
            recur(temp, listSize + 1, i + 1,  k - 1, target - candidates[i]);
        }
    }
}


int** combinationSum3(int k, int n, int** columnSizes, int* returnSize) {
    if(k == 0) return NULL;
    re = malloc(sizeof(int) * 3000);
    re_size = 0;
    columnSizes[0] = malloc(sizeof(int) * 3000);
    for(int i = 0; i < 3000; i++)
        columnSizes[0][i] = 0;
    re_col = columnSizes;
    candidates = malloc(sizeof(int) * 9);
    candidatesSize = 9;
    for(int i = 0; i < 9; i++)
        candidates[i] = i + 1;
    
    int *arr;
    int arr_size = 0;

    recur(arr, arr_size, 0, k, n);
    
    *returnSize = re_size;
    return re;
}
