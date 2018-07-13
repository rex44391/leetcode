struct TreeNode *root;

void recur(struct TreeNode *tn, int *postorder, int post_start, int post_end, int *inorder, int in_start, int in_end) {
    tn->val = postorder[post_end];
    tn->left = NULL;
    tn->right = NULL;
    if(post_start == post_end) return;
    
    int ptr = 0;
    while(inorder[in_end - ptr] != postorder[post_end])
        ptr++;
    
    if(in_end - ptr > in_start) {//have left child
        tn->left = malloc(sizeof(struct TreeNode));
        recur(tn->left, postorder, post_start, post_end - ptr - 1, inorder, in_start, in_end - ptr - 1);
    }
    if(in_end- ptr < in_end) {//have right child
        tn->right = malloc(sizeof(struct TreeNode));
        recur(tn->right, postorder, post_end - ptr, post_end - 1, inorder, in_end - ptr + 1, in_end);
    }
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(inorderSize == 0) return NULL;
    root = malloc(sizeof(struct TreeNode));
    
    recur(root, postorder, 0, postorderSize - 1, inorder, 0, inorderSize - 1);
    
    
    
    
    return root;
}
