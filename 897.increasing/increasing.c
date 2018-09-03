/*
* straight-forward one, just using a global pointer of pointer
* and inorder recursion to solve it
*/

struct TreeNode **ptr;

void inorder(struct TreeNode *tn) {
    
    if(tn->left)
        inorder(tn->left);
    
    *ptr = malloc(sizeof(struct TreeNode));
    (*ptr)->val = tn->val;
    (*ptr)->left = NULL;
    (*ptr)->right = NULL;
    ptr = &((*ptr)->right);
    
    if(tn->right)
        inorder(tn->right);
}

struct TreeNode* increasingBST(struct TreeNode* root) {
    if(!root) return NULL;
    
    struct TreeNode *re;
    ptr = &re; 
    inorder(root);
    return re;
}
