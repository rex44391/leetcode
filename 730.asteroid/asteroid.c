/*
* The algorithm for this problem is easy, 
* just loop the array, find the collision, and compute the result of collision.
* Iterate the above process until the array don't change anymore.
* However, implementing this algorithm with dynamic array is difficult and very inefficient
* (Think about that you need to adjust the array size 
*	and move all other elements for every collision result)
* So here I use a list structure and therefore it's O(n) space complexity
*/
typedef struct node {
    int val;
    struct node *next;
} Node;

Node *getNode(int val) {
    Node *n = malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    return n;
}

typedef struct list  {
    Node *head;
    Node *tail;
    int length;
} List;

List *getList() {
    List *l = malloc(sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    l->length = 0;
    return l;
}

void addList(List *l, int val) {
    Node *n = getNode(val);
    if(!l->tail) {
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = l->tail->next;
    }
    l->length++;
}

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    *returnSize = asteroidsSize;
    if(asteroidsSize < 2) return asteroids;

    List *l = getList();
    for(int i = 0; i < asteroidsSize; i++) {
        addList(l, asteroids[i]);
    }

    int temp_size;
    do {        
        temp_size = l->length;
        Node **ptr = &(l->head);
				//using a pointer of pinter is much easier for implementation
        while( (*ptr) && (*ptr)->next ) {
            if((*ptr)->val > 0 && (*ptr)->next->val < 0) {
                int temp_val = (*ptr)->next->val * (-1);
                if( (*ptr)->val > temp_val) {
                    (*ptr)->next = (*ptr)->next->next;
                    l->length--;
                } else if( (*ptr)->val < temp_val ) {
                    (*ptr) = (*ptr)->next;
                    l->length--;
                } else {
                    (*ptr) = (*ptr)->next->next;
                    l->length -= 2;
                }
            }
            if((*ptr))
                ptr = &((*ptr)->next);
        }
    } while(temp_size != l->length);
    
    Node *ptr = l->head;
    *returnSize = l->length;
    if(l->length == 0)
        return NULL;
    
    int *re = malloc(sizeof(int) * l->length);
    for(int i = 0; i < l->length; i++) {
        re[i] = ptr->val;
        ptr = ptr->next;
    }
    
    return re;
}
