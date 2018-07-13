struct ListNode* insertionSortList(struct ListNode* head) {
    if(!head) return NULL;
    struct ListNode *prev = head;
    struct ListNode *ptr = head->next;
    while(ptr) {
        struct ListNode **find = &head;
        bool swap = false;
        while( (*find) != ptr) {
            if(((*find)->val) > ptr->val) {
                prev->next = ptr->next;
                ptr->next = (*find);
                *find = ptr;
                ptr = prev->next;
                swap = true;
                break;
            }
            find = &((*find)->next);
        }
        if(!swap) {
            prev = prev->next;
            ptr = ptr->next;
        }
    }
    return head;
}
