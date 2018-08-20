/*
* Using post order traversal to get levels of a node's left and right subtrees,
* checking whether their difference is over 1.
* And return the node's own level number to its parent.
*/

bool re;

int post(struct TreeNode *tn) {
    int left = 0;
    int right = 0;
    int level;
    if(!tn->left && !tn->right) {
        return 1;
    }
        
    if(tn->left) {
        left = post(tn->left);
    }
    if(tn->right) {
        right = post(tn->right);
    }
    
    if(left > right) {
        if( (left - right) > 1)
            re = false;
        
        return left + 1;
    } else {
        if( (right - left) > 1)
            re = false;
        
        return right + 1;
    }
    
    
}


bool isBalanced(struct TreeNode* root) {
    if(!root) return true;
    re = true;
    post(root);
    return re;
}
