
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head) return NULL;
    struct ListNode **pptr = &head;
    if((*pptr)->next == NULL) return head;
    
    struct ListNode *ptr = head;
    int len = 0;
    while(ptr->next != NULL) {
        len++;
        ptr = ptr->next;
    }
    len++;
    k %= len;
    if(k == 0) return head;
    
    ptr->next = head;
    k = len - k;
    while(k > 0) {//find new head
        pptr = &((*pptr)->next);
        k--;
    }
    
    head = (*pptr);
    (*pptr) = NULL;
    
    return head;
}
