/*
* using the recursion to solve it
*/

struct TreeNode *new_root;

void recur(struct TreeNode* node, int v, int d) {
    if(d == 0) {
        struct TreeNode *temp = malloc(sizeof(struct TreeNode));
        temp->val = v;
        temp->left = node;
        temp->right = NULL;
        new_root = temp;
        return;
    }
    
    if(d == 1) {
        struct TreeNode *temp_left = NULL;
        struct TreeNode *temp_right = NULL;
        
        if(node->left)
            temp_left = node->left;
        if(node->right)
            temp_right = node->right;
        
        node->left = malloc(sizeof(struct TreeNode));
        node->left->val = v;
        node->left->left = temp_left;
        node->left->right = NULL;
        
        node->right = malloc(sizeof(struct TreeNode));
        node->right->val = v;
        node->right->left = NULL;
        node->right->right = temp_right;
        
    } else {
        if(node->left)
            recur(node->left, v, d - 1);
        if(node->right)
            recur(node->right, v, d - 1);
    }
}

struct TreeNode* addOneRow(struct TreeNode* root, int v, int d) {
    new_root = root;
    recur(root, v, d - 1);
    return new_root;
}
