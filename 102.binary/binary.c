int max_level;
int *level_count;
int **re;

void recurLevel(struct TreeNode *tn, int level) {
    if(level > max_level)
        max_level = level;
    if(tn->left)
        recurLevel(tn->left, level+1);
    if(tn->right)
        recurLevel(tn->right, level+1);
}

void recurCount(struct TreeNode *tn, int level) {
    level_count[level]++;
    if(tn->left)
        recurCount(tn->left, level+1);
    if(tn->right)
        recurCount(tn->right, level+1);
}

void recurRecord(struct TreeNode *tn, int level) {
    re[level][level_count[level]] = tn->val;
    level_count[level]++;
    if(tn->left)
        recurRecord(tn->left, level+1);
    if(tn->right)
        recurRecord(tn->right, level+1);
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(!root) return NULL;
    //step1. know the level
    max_level = -1;
    recurLevel(root, 0);
    
    //step2. know the count in each level
    max_level++;
    level_count = malloc(sizeof(int) * (max_level));
    for(int i = 0; i < max_level; i++)
        level_count[i] = 0;
    recurCount(root, 0);
    
    //step3. record into return array
    re = malloc(sizeof(int*) * (max_level));
    *columnSizes = (int *)malloc(sizeof(int)*max_level);
    for(int i = 0; i < max_level; i++) {
        re[i] = malloc(sizeof(int) * level_count[i]);
        columnSizes[0][i] = level_count[i];
    }
    for(int i = 0; i < max_level; i++) {
        level_count[i] = 0; //use the level count as ptr
    }
    recurRecord(root, 0);
    *returnSize = max_level;
    return re;
}
