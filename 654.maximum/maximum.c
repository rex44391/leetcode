

void recur(int *nums, int left, int right, struct TreeNode **tn) {
    if(left > right || left < 0)
        return;
    
    int max = INT_MIN;
    int index = -1;
    for(int i = left; i <= right; i++) {
        if(nums[i] > max) {
            max = nums[i];
            index = i;
        }
    }
    
    (*tn) = malloc(sizeof(struct TreeNode));
    (*tn)->val = nums[index];
    (*tn)->left = NULL;
    (*tn)->right = NULL;
    
    recur(nums, left, index - 1, &((*tn)->left) );
    recur(nums, index + 1, right, &((*tn)->right) );
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    struct TreeNode *head = NULL;
    struct TreeNOde **pptr = &head;
    recur(nums, 0, numsSize - 1, pptr);
    
    return head;
}
