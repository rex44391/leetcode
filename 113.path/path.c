

int **re;
int *colSizes;
int re_size;
int *list;
int list_size;

void recur(struct TreeNode *tn, int sum, int target) {
    list[list_size] = tn->val;
    list_size++;
    
    sum += tn->val;
    int ori_sum = sum;
    int ori_size = list_size;
    
    if(!tn->left && !tn->right) {
        if(sum == target) {
            re[re_size] = malloc(sizeof(int) * list_size );
            colSizes[re_size] = list_size;
            for(int i = 0; i < list_size; i++) {
                re[re_size][i] = list[i];
            }
            re_size++;
        }
        return;
    }
    
    if(tn->left) {
        recur(tn->left, sum, target);
    }
    
    sum = ori_sum;
    list_size = ori_size;
    
    if(tn->right) {
        recur(tn->right, sum, target);
    }
    list_size = ori_size;
}

int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
    if(!root) return NULL; 
    
    list = malloc(sizeof(int) * 1000);
    list_size = 0;
    
    colSizes = malloc(sizeof(int) * 1000);
    
    re = malloc(sizeof(int*) * 1000);
    re_size = 0;
    recur(root, 0, sum);
    
    columnSizes[0] = colSizes;
    *returnSize = re_size;
    return re;
}
