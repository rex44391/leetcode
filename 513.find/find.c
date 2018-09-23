/*
* it's just pre-order traversal.
* I use an array to record the value of each level's leftest node, 
* and we don't need this array actually.
* we just need an variable to record the deepest level instead.
* (beats 100%)
*/

int *re;
int re_size;

void recur(struct TreeNode *tn, int level) {
    if(level >= re_size) {
        re[re_size] = tn->val;
        re_size++;
    }
    if(tn->left)
        recur(tn->left, level+1);
    if(tn->right)
        recur(tn->right, level+1);
}

int findBottomLeftValue(struct TreeNode* root) {
    if(!root) return NULL;
    re = malloc(sizeof(int) * 1000);
    re_size = 0;
    recur(root, 0);
    return re[re_size - 1];
}
