/*
* using a table to record the value of each node, 
* and using the table's info to create the required list
*/

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
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
    
    int rev_index = 0;
    for(int i = 0; i < t_size; i++) {
        (*pptr) = malloc(sizeof(struct ListNode));
        if((i + 1) >= m && (i + 1) <= n) {
            (*pptr)->val = table[n - 1 - rev_index];
            rev_index++;
        } else {
            (*pptr)->val = table[i];
        }
        (*pptr)->next = NULL;
        pptr = &((*pptr)->next);
    }
    
    return re_head;
}
