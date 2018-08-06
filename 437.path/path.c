/*
* preorder traveral to visit each node with an int array to record the route
* then for each node, 
* check whether it and the val of the nodes in the route can meet the target sum.
*/
int *route;
int route_size;
int target;
int re;

void recur(struct TreeNode *tn) {
    int sum = 0;
    route[route_size] = tn->val;
    route_size++;
    for(int i = route_size - 1; i >= 0; i--) {
        sum += route[i];
        if(sum == target) {
            re++;
        }
    }
    
    int ori_size = route_size;
    
    if(tn->left) {
        recur(tn->left);
    }
    route_size = ori_size;
    
    if(tn->right) {
        recur(tn->right);
    }
    route_size = ori_size;
}


int pathSum(struct TreeNode* root, int sum) {
    if(!root) return 0;
    route = malloc(sizeof(int) * 3000);
    route_size = 0;
    target = sum;
    re = 0;
    recur(root);
    
    return re;
}
