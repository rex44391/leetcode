/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct array {
    int count;
    int size;
    struct ListNode **items;
} Array;

Array *getArray(int size) {
    Array *a = (Array*)malloc(sizeof(Array));
    a->count = 0;
    a->size = size;
    a->items = (struct ListNode **)malloc(sizeof(struct ListNode *) * a->size);
    return a;
}

void addArray(Array *array, struct ListNode *item) {
    if (array->count == array->size) {
        int newSize = array->size*2;
        struct ListNode **newItems = (struct ListNode **)malloc(sizeof(struct ListNode *) * newSize);
        memcpy(newItems, array->items, array->size*sizeof(struct ListNode *));
        free(array->items);
        array->items = newItems;
        array->size = newSize;
    }
    array->items[array->count++] = item;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(!head) return NULL;
    Array *a = getArray(10);
    
    struct ListNode *ptr = head;
    int counter = 0;
    while(ptr) {
        addArray(a, ptr);
        counter++;
        ptr = ptr->next;
    }
    
    if( (counter - n) == 0) {
        head = head->next;
    } else {
        ptr = (a->items[counter - n - 1]);
        ptr->next= ptr->next->next;
    }
    return head;
}
