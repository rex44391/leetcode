struct TreeNode *root2;

void preOrder(struct TreeNode *tn) {
    root2->val = tn->val;
    root2->right = NULL;
    root2->left = NULL;
    if(tn->left) {
        root2->right = malloc(sizeof(struct TreeNode));
        root2 = root2->right;
        preOrder(tn->left);
    }
    if(tn->right) {
        root2->right = malloc(sizeof(struct TreeNode));
        root2 = root2->right;
        preOrder(tn->right);
    }
} 

void flatten(struct TreeNode* root) {
    if(!root || (!root->left && !root->right)) return;
    root2 = malloc(sizeof(struct TreeNode));
    struct TreeNode *ptr = root2;
    preOrder(root);
    root->left = NULL;
    root->right = ptr->right;
}
