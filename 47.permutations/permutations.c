/*
* using recursive to solve this, it works but very slow.
* I think I can improve this by change the way of updating the nums array 
*/

int **re;
int re_size;

void recur(int *cand, int cand_size, int *list, int list_size) {
    if(cand_size < 0) return;
    if(cand_size == 0) {
        for(int i = 0; i < re_size; i++) {//check dupicate permutation
            bool flag = true;
            for(int j = 0; j < list_size; j++) {
                if(list[j] != re[i][j]) {
                    flag = false;
                    break;
                }    
            }
            if(flag)
                return;
        }
        re[re_size] = malloc(sizeof(int) * list_size);
        for(int i = 0; i < list_size; i++) {
            re[re_size][i] = list[i];
        }
        re_size++;
    } else {
        for(int i = 0; i < cand_size; i++) {
            int *temp = malloc(sizeof(int) * (list_size + 1));
            for(int j = 0; j < list_size; j++) {//update list by copy
                temp[j] = list[j];
            }
            temp[list_size] = cand[i];
            
            int *new_cand = malloc(sizeof(int) * (cand_size - 1));
            int ptr = 0;
            for(int j = 0; j < cand_size; j++) {//update cand
                if(j == i)
                    continue;
                new_cand[ptr] = cand[j];
                ptr++;
            }
            recur(new_cand, cand_size - 1, temp, list_size + 1);
        }
    }
}


int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    if(numsSize == 0) return NULL;
    re = malloc(sizeof(int*) * 3000);
    re_size = 0;
    int *list;
    recur(nums, numsSize, list, 0);
    *returnSize = re_size;
    return re;
}
