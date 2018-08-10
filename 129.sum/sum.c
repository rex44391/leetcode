



int counter;

void recur(struct TreeNode *tn, int sum) {
    sum *= 10;
    sum += tn->val;
    int ori = sum;
    
    if(!tn->left && !tn->right) {
        counter += sum;
    }
    
    
    
    if(tn->left) {
        recur(tn->left, sum);
    }
    
    sum = ori;
    
    if(tn->right) {
        recur(tn->right, sum);
    }
}

int sumNumbers(struct TreeNode* root) {
    if(!root) return 0;
    
    counter = 0;
    
    recur(root, 0);
    
    return counter;
}
