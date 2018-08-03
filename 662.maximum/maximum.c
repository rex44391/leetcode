/*
 * I use the recursive preorder traveral to visit each node
 * record the leftest's and rightest's indices of each level
 * finally find the biggest difference between two indeices of each level
 * It's not very efficient, and I will figure out some improvements
 */


int **table;
int table_size;

void inOrder(struct TreeNode *tn, int level, int index) {
    if(tn->left) {
        inOrder(tn->left, level + 1, index * 2);
    }
    
    if(table_size <= level)
        table_size = level + 1;
    
    if(index < table[level][0])
        table[level][0] = index;
    
    if(index > table[level][1])
        table[level][1] = index;
    
    if(tn->right) {
        inOrder(tn->right, level + 1, index * 2 + 1);
    }
}

int widthOfBinaryTree(struct TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    
    table = malloc(sizeof(int *) * 2000);
    table_size = 0;
    for(int i = 0; i < 2000; i++) {
        table[i] = malloc(sizeof(int) * 2);
        table[i][0] = INT_MAX;//record the min index
        table[i][1] = INT_MIN;//record the max index
    }
    
    inOrder(root, 0, 0);
    
    int max_width = INT_MIN;
    for(int i = 0; i < table_size; i++) {
        int temp = table[i][1] - table[i][0] + 1;
        if(temp > max_width)
            max_width = temp;
    }
    
    
    return max_width;
}
