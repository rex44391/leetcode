/*
* I recursively find the middle element of the array,
* and insert the element into tree with a common binary search tree insertion.
* Finding the middle one can guarantee the tree is balanced
* and will save you implementing an height-adjustment algorithm, like that of AVL tree
*/


struct TreeNode *root;
int size;

void insert(int val) {
    struct TreeNode **ptr = &root;
    while( (*ptr) ) {
        if(val > (*ptr)->val) {
            ptr = &((*ptr)->right);
        } else {
            ptr = &((*ptr)->left);
        }
    }
    *ptr = malloc(sizeof(struct TreeNode));
    (*ptr)->val = val;
    (*ptr)->left = NULL;
    (*ptr)->right = NULL;
}

void recur(int *arr, int l, int r) {
    if(l < 0 || r < 0 || l >= size || r >= size )
    if(l == r) {
        insert(arr[l]);
        return;
    }
    
    if(l > r) {
        return;
    } else {
        insert(arr[ (l + r)/2 ]);
        recur(arr, l, ((l + r)/2 - 1) );
        recur(arr, ((l + r)/2 + 1), r );
    }
    
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(numsSize == 0) return NULL;
    size = numsSize;
    root = NULL;
    recur(nums, 0, numsSize - 1);
    return root;
}
