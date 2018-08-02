/*
 * This algorithm is nothing new and can be seen in every DS textbook
 * first find the target, and then delete the target
 * if the target has child, find the max in its left subtree to replace itself
 * (or the min in its right subtree)
 */

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(!root) return NULL;
    struct TreeNode **ptr = &root;

    //search stage
    while((*ptr)) {
        if((*ptr)->val == key)
            break;

        if(key > (*ptr)->val) {
            ptr = &((*ptr)->right);
        } else {
            ptr = &((*ptr)->left);
        }
    }

    //delete stage
    if((*ptr)) {
        if( !((*ptr)->left) && !((*ptr)->right)) {
            (*ptr) = NULL;
        } else if( !((*ptr)->left) ) {//ptr->right exist, find min in right subtree
            struct TreeNode **replace = &((*ptr)->right);
            while((*replace)->left) {
                replace = &((*replace)->left);
            }
            (*ptr)->val = (*replace)->val;

            if((*replace)->right) {
                (*replace) = (*replace)->right;
            } else {
                (*replace) = NULL;
            }
        } else {//ptr->left exist, find max in left subtree
            struct TreeNode **replace = &((*ptr)->left);
            while((*replace)->right) {
                replace = &((*replace)->right);
            }
            (*ptr)->val = (*replace)->val;
            if((*replace)->left) {
                (*replace) = (*replace)->left;
            } else {
                (*replace) = NULL;
            }
        }
    }
    return root;
}
