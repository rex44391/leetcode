/*
* Search the mode by using inorder traversal to visit each node of BST,
* basically it's equivalent to search the mode in a list with ascending order.
* This algorithm beats other 100% submissions and meets the follow-up requiment
* (using only constant space)
*/

int *mode;
int mode_lower_bound;
int mode_size;
int prev;
int counter;

void recur(struct TreeNode *tn) {
    if(tn->left) 
        recur(tn->left);
    
    if(tn->val != prev) {
        if(counter == mode_lower_bound) {
            mode[mode_size] = prev;
            mode_size++;
            prev = tn->val;
            counter = 1;
        } else if(counter > mode_lower_bound) {
            mode_lower_bound = counter;
            mode[0] = prev;
            mode_size = 1;
            prev = tn->val;
            counter = 1;
        } else {
            counter = 1;
            prev = tn->val;
        }
    } else {
        counter++;
    }
    
    if(tn->right)
        recur(tn->right);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    if(!root)
        return NULL;
    
    mode = malloc(sizeof(int) * 5000);
    mode_lower_bound = -1;
    mode_size = 0;
    counter = 0;
    prev = INT_MAX;
    recur(root);
    if(counter == mode_lower_bound) {
        mode[mode_size] = prev;
        mode_size++;
    }  else if(counter > mode_lower_bound) {
        mode_lower_bound = counter;
        mode[0] = prev;
        mode_size = 1;
    }
    
    *returnSize = mode_size;
    return mode;
}
