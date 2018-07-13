static int counter = 0;


typedef struct leaf {
    int val;
    struct leaf *left;
    struct leaf *right;
} Leaf;

Leaf *getLeaf(int val) {
    Leaf *l = (Leaf*)malloc(sizeof(Leaf));
    l->val = val;
    l->left = NULL;
    l->right = NULL;
    return l;
}

typedef struct tree {
    Leaf *head;
} Tree;

Tree *getTree() {
    Tree *t = (Tree*)malloc(sizeof(Tree));
    t->head = NULL;
    return t;
}

void addLeaf(Tree *t, int val) {
    Leaf *l = getLeaf(val);
    
    Leaf **pptr = &(t->head);
    
    while(*pptr) {
        if(val > (*pptr)->val)
            pptr = &((*pptr)->right);
        else
            pptr = &((*pptr)->left);
    }
    *pptr = l;
    return;
}

void inOrder(Leaf *l, int *nums) {
    if(!l) return;
    
    if(l->left)
        inOrder(l->left, nums);
    
    nums[counter] = l->val;
    counter++;
    
    if(l->right)
        inOrder(l->right, nums);
}

void sortColors(int* nums, int numsSize) {
    if(numsSize == 0 || numsSize == 1)
        return;
    Tree *t = getTree();
    
    for(int i = 0; i < numsSize; i++) {
        addLeaf(t, nums[i]);
    }
    
    counter = 0;
    inOrder(t->head, nums);
    
    return;
}
