

bool is_pruned;

void recur(struct TreeNode **tn_pptr) {
    if(!((*tn_pptr)->left) && !((*tn_pptr)->right)) {
        if( (*tn_pptr)->val == 0) {
            (*tn_pptr) = NULL;
            is_pruned = true;
        }
        return;
    }
    
    if( (*tn_pptr)->left ) {
        recur( &((*tn_pptr)->left) );
    }
    
    if( (*tn_pptr)->right ) {
        recur( &((*tn_pptr)->right) );
    }
}


struct TreeNode* pruneTree(struct TreeNode* root) {
    if(!root) return NULL;
    
    struct TreeNode **root_pptr = &root;
    
    
    while(true) {
        is_pruned = false;
        recur(root_pptr);
        if(!is_pruned || !(*root_pptr) )
            break;
    }
    return root;
}
