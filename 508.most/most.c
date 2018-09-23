/*
* I just use post-order traversal to get each node's sums of left and right subtrees
* and record all the subtree sum in an array.
* Finally, search mode in that array and return
* (got 100%)
*/

int cmpfunc (const int * a, const int * b) {
   if(*a > *b)
       return 1;
    return 0;
}


int *result;
int result_size;

int recur(struct TreeNode *tn) {
    int left_result = 0;
    int right_result = 0;
    if(tn->left)
        left_result = recur(tn->left);
    if(tn->right)
        right_result = recur(tn->right);
    
    int re = left_result + right_result + tn->val;
    result[result_size] = re;
    result_size++;
    return re;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    if(!root) return NULL;
    result = malloc(sizeof(int) * 20000);
    result_size = 0;
    recur(root);
    
    int *re = malloc(sizeof(int) * 20000);
    int re_size = 0;
    qsort(result, result_size, sizeof(int), cmpfunc);
    
    int prev = result[0];
    int counter = 1;
    int freq = -1;
    for(int i = 1; i < result_size; i++) {
        if(result[i] == prev) {
            counter++;
        } else {
            if(counter > freq) {
                re_size = 0;
                re[re_size] = prev;
                re_size++;
                freq = counter;
            } else if(counter == freq) {
                re[re_size] = prev;
                re_size++;
            }
            prev = result[i];
            counter = 1;
        }
    }
    if(counter > freq) {
        re_size = 0;
        re[re_size] = prev;
        re_size++;
        freq = counter;
    } else if(counter == freq) {
        re[re_size] = prev;
        re_size++;
    }
    
    *returnSize = re_size;
    return re;
}
