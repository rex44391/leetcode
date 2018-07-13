struct TreeNode *root;


void recur(struct TreeNode *tn, int *preorder, int pre_start, int pre_end, int *inorder, int in_start, int in_end) {

    
    tn->val = preorder[pre_start];
    tn->left = NULL;
    tn->right = NULL;
    
    if(pre_start == pre_end) return;
    
    
    int ptr = 0;
    while(inorder[in_start + ptr] != preorder[pre_start])
        ptr++;
    
    if(in_start + ptr > in_start) {//have left child
        tn->left = malloc(sizeof(struct TreeNode));
        recur(tn->left, preorder, pre_start+1, pre_start+ptr, inorder, in_start, in_start+ptr-1);
    }
    
    if(in_start + ptr < in_end) {//have right child
        tn->right = malloc(sizeof(struct TreeNode));
        recur(tn->right, preorder, pre_start+ptr+1, pre_end, inorder, in_start+ptr+1, in_end);
    }
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize == 0) return NULL;
    root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    
    int ptr = 0;
    while(inorder[ptr] != preorder[0]) 
        ptr++;
    
    if(ptr > 0) {// have left child
        root->left = malloc(sizeof(struct TreeNode));
        recur(root->left, preorder, 1, ptr, inorder, 0, ptr-1);
    }
    
    if(ptr < inorderSize -1 ) {//have right child
        root->right = malloc(sizeof(struct TreeNode));
        recur(root->right, preorder, ptr+1, preorderSize-1, inorder, ptr+1, inorderSize-1);
    }
    
    return root;
}
