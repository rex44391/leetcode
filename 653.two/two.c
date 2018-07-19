/* preorder recursive every node in the tree
* and for each node, use bifind(line 6)function to search the another node with which to sum up to target
*/

bool re;

bool biFind(struct TreeNode* root, struct TreeNode* tn, int target) {
    struct TreeNode* ptr = root;
    while(ptr) {
        if(ptr->val == target) {
            if(ptr != tn) {
                return true;
            } else {
                ptr  = ptr->left;
            }
        } else if(ptr->val > target) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }
    return false;
} 


void recur(struct TreeNode* root, struct TreeNode* tn, int k) {
    bool a = biFind(root, tn, k - tn->val);
    if(a) {
        re = true;
        return;
    }
    if(tn->left && !re)
        recur(root, tn->left, k);
    if(tn->right && !re)
        recur(root, tn->right, k);
}

bool findTarget(struct TreeNode* root, int k) {
    if(!root) return false;
    re = false;
    recur(root, root, k);
    return re;
}
