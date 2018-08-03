/*
 * just create two new lists and add each node to the correspond list
 * finally append two lists together
*/

struct ListNode* partition(struct ListNode* head, int x) {
    if(!head) return NULL;
    struct ListNode *head1 = NULL;
    struct ListNode **ptr1 = &head1;

    struct ListNode *head2 = NULL;
    struct ListNode **ptr2 = &head2;

    struct ListNode *ptr = head;
    while(ptr) {
        if(ptr->val < x) {
            (*ptr1) = malloc(sizeof(struct ListNode));
            (*ptr1)->val = ptr->val;
            (*ptr1)->next = NULL;
            ptr1 = &((*ptr1)->next);
        } else {
            (*ptr2) = malloc(sizeof(struct ListNode));
            (*ptr2)->val = ptr->val;
            (*ptr2)->next = NULL;
            ptr2 = &((*ptr2)->next);
        }

        ptr = ptr->next;
    }
    (*ptr1) = head2;

    return head1;
}
