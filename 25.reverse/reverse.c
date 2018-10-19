/*
* beats 100%, using a table to record the value of each node,
* and create a new list based on the table and return the new list.
* so time and space complexities are O(n)
* this way is much easier than solving it in place!
*/

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(!head) return NULL;
    int *table = malloc(sizeof(int) * 5000);
    int t_size = 0;
    struct ListNode *ptr = head;
    while(ptr != NULL) {
        table[t_size] = ptr->val;
        t_size++;
        ptr = ptr->next;
    }
    
    struct ListNode *re_head;
    struct ListNode **pptr = &(re_head);
    
    int times = t_size / k;
    int remaining = t_size % k;
    
    for(int i = 0; i < times; i++) {
        for(int j = 0; j < k; j++) {
            (*pptr) = malloc(sizeof(struct ListNode));
            (*pptr)->val = table[ (i * k) + (k - j - 1)];
            (*pptr)->next = NULL;
            pptr = &((*pptr)->next);
        }
    }
    
    //for remaining
    for(int i = 0; i < remaining; i++) {
        (*pptr) = malloc(sizeof(struct ListNode));
        (*pptr)->val = table[t_size - remaining + i];
        (*pptr)->next = NULL;
        pptr = &((*pptr)->next);
    }
    
    return re_head;
}
