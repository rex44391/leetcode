/*
* while doing inorder traversal, computing the differences
*/

int min;
int prev;

void recur(struct TreeNode *tn) {
    if(tn->left)
        recur(tn->left);
    
    if(prev == 9191779)
        prev = tn->val;
    else {
        if( (tn->val - prev) < min) {
            min = tn->val -prev;
        }
        prev = tn->val;
    }
    
    if(tn->right)
        recur(tn->right);
}

int getMinimumDifference(struct TreeNode* root) {
    if(!root) return NULL;
    min = INT_MAX;
    prev = 9191779;
		// a special number which is almost not possible to have it
    //in test case
		recur(root);
    return min;
}
