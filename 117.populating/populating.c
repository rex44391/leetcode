void first_recur(struct TreeLinkNode *tn) {
    if(tn->left && tn->right)
        tn->left->next = tn->right;
    
    if(tn->left)
        first_recur(tn->left);
    if(tn->right)
        first_recur(tn->right);
}

bool changed;

void second_recur(struct TreeLinkNode *tn) {
    
    if(tn->right && tn->right->next == NULL) {
        struct TreeLinkNode *ptr = tn->next;
        while(ptr) {
            if(ptr->left || ptr->right)
                break;
            ptr = ptr->next;
        }
        if(ptr) {
            if(ptr->left) {
                tn->right->next = ptr->left;
                changed = true;
            } else if(ptr->right) {
                tn->right->next = ptr->right;
                changed = true;
            }
        }    
    } else if(tn->left && tn->left->next == NULL) {
        struct TreeLinkNode *ptr = tn->next;
        while(ptr) {
            if(ptr->left || ptr->right)
                break;
            ptr = ptr->next;
        }
        if(ptr) {
            if(ptr->left) {
                tn->left->next = ptr->left;
                changed = true;
            } else if(ptr->right) {
                tn->left->next = ptr->right;
                changed = true;
            }
        }
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
    
    changed = true;
    while(changed) {
        changed = false;
        second_recur(root);
    }
    
}
