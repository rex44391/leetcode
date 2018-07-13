void first_recur(struct TreeLinkNode *tn) {
    if(tn->left && tn->right)
        tn->left->next = tn->right;
    
    if(tn->left)
        first_recur(tn->left);
    if(tn->right)
        first_recur(tn->right);
}

void second_recur(struct TreeLinkNode *tn) {
    if(tn->right && tn->next && tn->next->left) {
        tn->right->next = tn->next->left;
    }
    if(tn->left)
        second_recur(tn->left);
    if(tn->right)
        second_recur(tn->right);
}


void connect(struct TreeLinkNode *root) {
    if(!root) return NULL;
    root->next = NULL;
    first_recur(root);
    second_recur(root);
}
